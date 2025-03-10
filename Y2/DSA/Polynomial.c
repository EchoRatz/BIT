/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */  
 
#include <stdio.h>  
#include <stdlib.h>  
  
typedef struct node  
{   int    coef, exp;  
    struct node  *next;  
} NODE;  
  
void multiplication( NODE *, NODE * , NODE * );  
void input( NODE * );  
void output( NODE * );  
  
void input( NODE * head )  
{   int flag, sign, sum, x;  
    char c;  
  
    NODE * p = head;  
  
    while ( (c=getchar()) !='\n' )  
    {  
        if ( c == '<' )  
        {    sum = 0;  
             sign = 1;  
             flag = 1;  
        }  
        else if ( c =='-' )  
             sign = -1;  
        else if( c >='0'&& c <='9' )  
        {    sum = sum*10 + c - '0';  
        }  
        else if ( c == ',' )  
        {    if ( flag == 1 )  
             {    x = sign * sum;  
                  sum = 0;  
                  flag = 2;  
          sign = 1;  
             }  
        }  
        else if ( c == '>' )  
        {    p->next = ( NODE * ) malloc( sizeof(NODE) );  
             p->next->coef = x;  
             p->next->exp  = sign * sum;  
             p = p->next;  
             p->next = NULL;  
             flag = 0;  
        }  
    }  
}  
  
void output( NODE * head )  
{  
    while ( head->next != NULL )  
    {   head = head->next;  
        printf("<%d,%d>,", head->coef, head->exp );  
    }  
    printf("\n");  
}  
  
int main()  
{   NODE * head1, * head2, * head3;  
  
    head1 = ( NODE * ) malloc( sizeof(NODE) );  
    input( head1 );  
  
    head2 = ( NODE * ) malloc( sizeof(NODE) );  
    input( head2 );  
  
    head3 = ( NODE * ) malloc( sizeof(NODE) );  
    head3->next = NULL;  
    multiplication( head1, head2, head3 );  
  
    output( head3 );  
    return 0;  
}  
  
/* PRESET CODE END - NEVER TOUCH CODE ABOVE */  
#include <string.h>

typedef struct term_node {
    int coef;
    int exp;
    struct term_node *next;
} TERM_NODE;

#define HASH_TABLE_SIZE 10007  // A prime number for hash table size

TERM_NODE *hash_table[HASH_TABLE_SIZE];

unsigned int hash_function(int exp) {
    // Simple hash function using modulus
    return ((unsigned int)(exp)) % HASH_TABLE_SIZE;
}

void insert_term_hash(int coef, int exp) {
    if (coef == 0) {
        return;
    }

    unsigned int index = hash_function(exp);
    TERM_NODE *node = hash_table[index];

    // Search for the exponent in the chain
    while (node != NULL) {
        if (node->exp == exp) {
            // Exponent found, update the coefficient
            node->coef += coef;
            return;
        }
        node = node->next;
    }

    // Exponent not found, create a new term
    TERM_NODE *new_node = (TERM_NODE *)malloc(sizeof(TERM_NODE));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }
    new_node->coef = coef;
    new_node->exp = exp;
    new_node->next = hash_table[index];
    hash_table[index] = new_node;
}

int compare_terms(const void *a, const void *b) {
    TERM_NODE *term_a = *(TERM_NODE **)a;
    TERM_NODE *term_b = *(TERM_NODE **)b;

    if (term_a->exp < term_b->exp) return -1;
    else if (term_a->exp > term_b->exp) return 1;
    else return 0;
}

void multiplication(NODE *h1, NODE *h2, NODE *h3) {
    NODE *p1 = h1->next;
    NODE *p2;

    // Initialize hash table
    memset(hash_table, 0, sizeof(hash_table));

    // Multiply terms and store in hash table
    while (p1 != NULL) {
        p2 = h2->next;
        while (p2 != NULL) {
            int exp_sum = p1->exp + p2->exp;
            int coef_product = p1->coef * p2->coef;
            insert_term_hash(coef_product, exp_sum);
            p2 = p2->next;
        }
        p1 = p1->next;
    }

    // Collect terms from hash table
    int term_count = 0;
    int max_terms = 10000; // Adjust as needed based on expected number of unique exponents
    TERM_NODE **terms_list = (TERM_NODE **)malloc(max_terms * sizeof(TERM_NODE *));
    if (terms_list == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }

    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        TERM_NODE *node = hash_table[i];
        while (node != NULL) {
            if (node->coef != 0) {
                if (term_count >= max_terms) {
                    // Resize the terms_list array if needed
                    max_terms *= 2;
                    terms_list = (TERM_NODE **)realloc(terms_list, max_terms * sizeof(TERM_NODE *));
                    if (terms_list == NULL) {
                        fprintf(stderr, "Memory allocation failed.\n");
                        exit(1);
                    }
                }
                terms_list[term_count++] = node;
            }
            node = node->next;
        }
    }

    // If no terms, result is zero polynomial
    if (term_count == 0) {
        h3->next = (NODE *)malloc(sizeof(NODE));
        if (h3->next == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");
            exit(1);
        }
        h3->next->coef = 0;
        h3->next->exp = 0;
        h3->next->next = NULL;

        free(terms_list);
        return;
    }

    // Sort terms by exponent
    qsort(terms_list, term_count, sizeof(TERM_NODE *), compare_terms);

    // Build result polynomial
    NODE *current = h3;
    for (int i = 0; i < term_count; i++) {
        NODE *new_node = (NODE *)malloc(sizeof(NODE));
        if (new_node == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");
            exit(1);
        }
        new_node->coef = terms_list[i]->coef;
        new_node->exp = terms_list[i]->exp;
        new_node->next = NULL;
        current->next = new_node;
        current = new_node;
    }

    // Free terms_list
    free(terms_list);

    // Free hash table
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        TERM_NODE *node = hash_table[i];
        while (node != NULL) {
            TERM_NODE *temp = node;
            node = node->next;
            free(temp);
        }
        hash_table[i] = NULL;
    }
}
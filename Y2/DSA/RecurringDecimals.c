/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */  
 
#include <stdio.h>  
#include <stdlib.h>  
  
typedef struct node  
{   int         data;  
    struct node * next;  
} NODE;  
  
void output( NODE *, int );  
void change( int, int, NODE * );  
  
void output( NODE * head, int kk )  
{   int k=0;  
  
    printf("0.");  
    while ( head->next != NULL && k<kk )  
    {   printf("%d", head->next->data );  
        head = head->next;  
        k ++;  
    }  
    printf("\n");  
}  
  
int main()  
{   int n, m,k;  
    NODE * head;  
  
    scanf("%d%d%d", &n, &m, &k);  
    head = (NODE *)malloc( sizeof(NODE) );  
    head->next = NULL;  
    head->data = -1;  
    change( n, m, head );  
    output( head,k );  
    return 0;  
}  
  
/* PRESET CODE END - NEVER TOUCH CODE ABOVE */  
void change(int n, int m, NODE *head) {  
    int remainder = n % m;  
    NODE *current = head;  
  
    // Define a structure to store remainders and corresponding nodes  
    typedef struct remainder_node {  
        int remainder;  
        NODE *node;  
        struct remainder_node *next;  
    } REM_NODE;  
  
    REM_NODE *rem_list = NULL;  
  
    while (1) {  
        // Check if remainder is zero (division ends)  
        if (remainder == 0) {  
            current->next = NULL; // End the linked list  
            // Free the remainder list  
            while (rem_list != NULL) {  
                REM_NODE *temp = rem_list;  
                rem_list = rem_list->next;  
                free(temp);  
            }  
            return;  
        }  
  
        // Check if this remainder has been seen before  
        REM_NODE *temp_rem = rem_list;  
        while (temp_rem != NULL) {  
            if (temp_rem->remainder == remainder) {  
                // Repeating sequence detected  
                current->next = temp_rem->node->next;  
                // Free the remainder list  
                while (rem_list != NULL) {  
                    REM_NODE *temp = rem_list;  
                    rem_list = rem_list->next;  
                    free(temp);  
                }  
                return;  
            }  
            temp_rem = temp_rem->next;  
        }  
  
        // Create a new remainder node  
        REM_NODE *new_rem_node = (REM_NODE *)malloc(sizeof(REM_NODE));  
        if (new_rem_node == NULL) {  
            fprintf(stderr, "Memory allocation error\n");  
            exit(1);  
        }  
        new_rem_node->remainder = remainder;  
        new_rem_node->node = current; // Store current node  
        new_rem_node->next = rem_list;  
        rem_list = new_rem_node;  
  
        // Multiply remainder by 10 for the next digit  
        int temp = remainder * 10;  
        int digit = temp / m;  
        remainder = temp % m; // Update remainder  
  
        // Create a new node with the calculated digit  
        NODE *new_node = (NODE *)malloc(sizeof(NODE));  
        if (new_node == NULL) {  
            fprintf(stderr, "Memory allocation error\n");  
            exit(1);  
        }  
        new_node->data = digit;  
        new_node->next = NULL;  
  
        // Link the new node to the list  
        current->next = new_node;  
        current = new_node;  
    }  
}  
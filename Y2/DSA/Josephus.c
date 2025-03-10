#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int person;
    struct Node *next;
} Node;

Node* createNode(int person){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->person = person;
    newNode->next = NULL;
    return newNode;
}

Node* createCircularLinkedList(int n){
   Node* head = createNode(1);
   Node* current = head;

   for(int i = 2; i <= n; i++){
    current->next = createNode(i);
    current = current->next;
   }

   current->next = head;
   return head;
}

void josephus(int n, int k, int m){
    if(n < 1 || k < 1 || m < 1){
        printf("n, m, k must bigger than 0.\n");
        return;
    }
    if(k > n){
        printf("k should not bigger than n.\n");
        return;
    }

    
    Node* head = createCircularList(n);
    Node* prev = NULL;
    Node* current = head;

    for(int i = 1; i < k; i++){
        prev = current;
        current = current->next;
    }

    int count = 0;
    while (n > 0) {
        for (int i = 1; i < m; i++) {
            prev = current;
            current = current->next;
        }

        printf("%d", current->person);
        count++;
        n--;

        if (n > 0) {
            if (count % 10 == 0) {
                printf("\n");
            } else {
                printf(" ");
            }
        }

        prev->next = current->next;
        free(current);
        current = prev->next;
    }
    printf("\n");
}

int main(){
    int n, k, m;

    scanf("%d, %d, %d", &n, &k, &m);

    if (n <= 0 || k <= 0 || m <= 0) {
        printf("n, m, k must be bigger than 0.\n");
        return;
    }

    if (k > n) {
        printf("k should not be bigger than n.\n");
        return;
    }

    josephus(n, k, m);
    return 0;
}
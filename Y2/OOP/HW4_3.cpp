#include <iostream>

struct Node{
    int value;
    Node* next;
};

void createList(Node* head, int length){
    Node* current = head;
    for (int i = 1; i < length; ++i){
        current->value = i;
        current->next = new Node;
        current = current->next;
    }
    current->value = length;
    current->next = nullptr;
}

void printList(Node* head){
    Node* current = head;
    while (current != nullptr){
        std::cout << "Value: " << current->value << ", Pointer: " << current->next << std::endl;
        current = current->next;
    }
}

int main(){
    Node* head = new Node;
    createList(head, 5);
    printList(head);

    // Clean up memory
    Node* current = head;
    while (current != nullptr){
        Node* next = current->next;
        delete current;
        current = next;
    }
    return 0;
}
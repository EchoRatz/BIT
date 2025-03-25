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

struct LinkedList {
    Node* head;

    LinkedList() : head(nullptr) {}

    void createList(int length) {
        head = new Node;
        Node* current = head;
        for (int i = 1; i < length; ++i) {
            current->value = i;
            current->next = new Node;
            current = current->next;
        }
        current->value = length;
        current->next = nullptr;
    }

    void printList() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << "Value: " << current->value << ", Pointer: " << current->next << std::endl;
            current = current->next;
        }
    }

    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    LinkedList list;
    list.createList(5);
    list.printList();
    return 0;
}
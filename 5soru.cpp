#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char data[50];
    struct Node* next;
};

struct Node* createNode(char data[]) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->data, data);
    newNode->next = NULL;
    return newNode;
}

void append(struct Node** head, char data[]) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* current = *head;
    while (current->next) {
        current = current->next;
    }
    current->next = newNode;
}

void searchAndDeleteNext(struct Node** head, char target[]) {
    struct Node* current = *head;
    while (current && current->next) {
        if (strcmp(current->data, target) == 0) {
            struct Node* toDelete = current->next;
            current->next = toDelete->next;
            free(toDelete);
            return;
        }
        current = current->next;
    }
}

void display(struct Node* head) {
    struct Node* current = head;
    while (current) {
        printf("%s -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    append(&head, "Ogrenci1");
    append(&head, "Ogrenci2");
    append(&head, "Ogrenci3");

    printf("Original List: ");
    display(head);

    char target[] = "Ogrenci2";
    searchAndDeleteNext(&head, target);

    printf("List After Deleting Next Node of %s: ", target);
    display(head);

    return 0;
}


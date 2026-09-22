#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
void insert(struct Node **head, int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}
void deleteNode(struct Node **head, int value) {
    struct Node *temp = *head;
    struct Node *prev = NULL;
    if (temp != NULL && temp->data == value) {
        *head = temp->next;
        free(temp);
        printf("%d deleted successfully.\n", value);
        return;
    }
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("%d not found in the list.\n", value);
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("%d deleted successfully.\n", value);
}
void traverse(struct Node *head) {
    struct Node *temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
    struct Node *head = NULL;
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    printf("After insertion:\n");
    traverse(head);
    deleteNode(&head, 20);
    printf("After deletion:\n");
    traverse(head);
    return 0;
}

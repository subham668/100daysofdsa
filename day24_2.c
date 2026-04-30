#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* next;
};

struct Node* createNode(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->val = val;
    n->next = NULL;
    return n;
}

struct Node* insert(struct Node* head, int val) {
    if (head == NULL) return createNode(val);

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = createNode(val);
    return head;
}

struct Node* removeElements(struct Node* head, int val) {
    while (head != NULL && head->val == val) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    struct Node* curr = head;

    while (curr != NULL && curr->next != NULL) {
        if (curr->next->val == val) {
            struct Node* temp = curr->next;
            curr->next = temp->next;
            free(temp);
        } else {
            curr = curr->next;
        }
    }

    return head;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
}

int main() {
    int n, x, val;
    struct Node* head = NULL;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        head = insert(head, x);
    }

    scanf("%d", &val);

    head = removeElements(head, val);

    printList(head);

    return 0;
}
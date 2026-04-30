#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createList(int arr[], int n) {
    struct Node *head = NULL, *temp = NULL, *last = NULL;

    for (int i = 0; i < n; i++) {
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = arr[i];
        temp->next = NULL;

        if (head == NULL) {
            head = temp;
            last = temp;
        } else {
            last->next = temp;
            last = temp;
        }
    }
    return head;
}

struct Node* rotateRight(struct Node* head, int k, int n) {
    if (!head || k == 0) return head;

    k = k % n;
    if (k == 0) return head;

    struct Node* temp = head;
    int count = 1;

    while (temp->next) {
        temp = temp->next;
        count++;
    }

    temp->next = head;

    int steps = n - k;
    temp = head;

    for (int i = 1; i < steps; i++) {
        temp = temp->next;
    }

    struct Node* newHead = temp->next;
    temp->next = NULL;

    return newHead;
}

void printList(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, k;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &k);

    struct Node* head = createList(arr, n);
    head = rotateRight(head, k, n);

    printList(head);

    return 0;
}
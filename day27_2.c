#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = val;
    n->next = NULL;
    return n;
}

int removeCycle(struct Node *head) {
    struct Node *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            slow = head;

            if (slow == fast) {
                while (fast->next != slow)
                    fast = fast->next;
            } else {
                while (slow->next != fast->next) {
                    slow = slow->next;
                    fast = fast->next;
                }
            }

            fast->next = NULL;
            return 1;
        }
    }

    return 0;
}

int main() {
    struct Node* head = createNode(1);
    head->next = createNode(3);
    head->next->next = createNode(4);

    head->next->next->next = head->next;

    if (removeCycle(head))
        printf("true");
    else
        printf("false");

    return 0;
}
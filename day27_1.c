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

struct Node* insert(struct Node* head, int val) {
    if (head == NULL) return createNode(val);

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = createNode(val);
    return head;
}

int getLength(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

struct Node* getIntersection(struct Node* h1, struct Node* h2) {
    int len1 = getLength(h1);
    int len2 = getLength(h2);

    int diff = abs(len1 - len2);

    if (len1 > len2) {
        for (int i = 0; i < diff; i++)
            h1 = h1->next;
    } else {
        for (int i = 0; i < diff; i++)
            h2 = h2->next;
    }

    while (h1 != NULL && h2 != NULL) {
        if (h1 == h2)
            return h1;
        h1 = h1->next;
        h2 = h2->next;
    }

    return NULL;
}

int main() {
    int n, m, x;
    struct Node *l1 = NULL, *l2 = NULL;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        l1 = insert(l1, x);
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        l2 = insert(l2, x);
    }

    struct Node* temp1 = l1;
    struct Node* intersect = NULL;

    while (temp1 != NULL) {
        struct Node* temp2 = l2;
        while (temp2 != NULL) {
            if (temp1->data == temp2->data) {
                intersect = temp1;
                break;
            }
            temp2 = temp2->next;
        }
        if (intersect != NULL) break;
        temp1 = temp1->next;
    }

    if (intersect != NULL) {
        struct Node* t = l2;
        while (t->data != intersect->data)
            t = t->next;
        t->next = intersect;
    }

    struct Node* res = getIntersection(l1, l2);

    if (res != NULL)
        printf("%d", res->data);
    else
        printf("No Intersection");

    return 0;
}
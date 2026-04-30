#include <stdio.h>
#include <string.h>

#define EMPTY -1

int table[1000];
int m;

int hash(int key) {
    return key % m;
}

void insert(int key) {
    int h = hash(key);
    for(int i = 0; i < m; i++) {
        int idx = (h + i * i) % m;
        if(table[idx] == EMPTY) {
            table[idx] = key;
            return;
        }
    }
}

void search(int key) {
    int h = hash(key);
    for(int i = 0; i < m; i++) {
        int idx = (h + i * i) % m;
        if(table[idx] == EMPTY) {
            printf("NOT FOUND\n");
            return;
        }
        if(table[idx] == key) {
            printf("FOUND\n");
            return;
        }
    }
    printf("NOT FOUND\n");
}

int main() {
    int q;
    scanf("%d", &m);
    scanf("%d", &q);

    for(int i = 0; i < m; i++) table[i] = EMPTY;

    while(q--) {
        char op[10];
        int key;
        scanf("%s %d", op, &key);

        if(strcmp(op, "INSERT") == 0) insert(key);
        else if(strcmp(op, "SEARCH") == 0) search(key);
    }

    return 0;
}
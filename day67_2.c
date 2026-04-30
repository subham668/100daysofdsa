#include <stdio.h>
#include <stdlib.h>

int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* returnSize) {
    int* indegree = (int*)calloc(numCourses, sizeof(int));
    int** adj = (int**)malloc(numCourses * sizeof(int*));
    int* adjSize = (int*)calloc(numCourses, sizeof(int));

    for (int i = 0; i < numCourses; i++)
        adj[i] = (int*)malloc(numCourses * sizeof(int));

    for (int i = 0; i < prerequisitesSize; i++) {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];
        adj[b][adjSize[b]++] = a;
        indegree[a]++;
    }

    int* queue = (int*)malloc(numCourses * sizeof(int));
    int front = 0, rear = 0;

    for (int i = 0; i < numCourses; i++)
        if (indegree[i] == 0)
            queue[rear++] = i;

    int* result = (int*)malloc(numCourses * sizeof(int));
    int index = 0;

    while (front < rear) {
        int u = queue[front++];
        result[index++] = u;

        for (int i = 0; i < adjSize[u]; i++) {
            int v = adj[u][i];
            indegree[v]--;
            if (indegree[v] == 0)
                queue[rear++] = v;
        }
    }

    if (index != numCourses) {
        *returnSize = 0;
        return NULL;
    }

    *returnSize = numCourses;
    return result;
}

int main() {
    int numCourses = 4;
    int prerequisitesSize = 4;

    int data[4][2] = {{1,0},{2,0},{3,1},{3,2}};
    int* prerequisites[4];

    for (int i = 0; i < 4; i++)
        prerequisites[i] = data[i];

    int returnSize;
    int* order = findOrder(numCourses, prerequisites, prerequisitesSize, NULL, &returnSize);

    if (returnSize == 0) {
        printf("No valid ordering\n");
    } else {
        for (int i = 0; i < returnSize; i++)
            printf("%d ", order[i]);
    }

    return 0;
}
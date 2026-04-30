#include <stdio.h>

int leastInterval(char tasks[], int size, int n){
    int freq[26] = {0};

    for(int i=0;i<size;i++){
        freq[tasks[i]-'A']++;
    }

    int maxFreq = 0;
    for(int i=0;i<26;i++){
        if(freq[i] > maxFreq){
            maxFreq = freq[i];
        }
    }

    int countMax = 0;
    for(int i=0;i<26;i++){
        if(freq[i] == maxFreq){
            countMax++;
        }
    }

    int result = (maxFreq - 1) * (n + 1) + countMax;

    return result > size ? result : size;
}

int main(){
    int n, size;
    scanf("%d",&size);

    char tasks[size];
    for(int i=0;i<size;i++){
        scanf(" %c",&tasks[i]);
    }

    scanf("%d",&n);

    printf("%d", leastInterval(tasks,size,n));

    return 0;
}
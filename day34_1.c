#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* top=NULL;

void push(int x){
    struct Node* t=(struct Node*)malloc(sizeof(struct Node));
    t->data=x;
    t->next=top;
    top=t;
}

int pop(){
    struct Node* t=top;
    int x=t->data;
    top=top->next;
    free(t);
    return x;
}

int eval(char* exp){
    int i=0;
    while(exp[i]){
        if(exp[i]==' '){i++;continue;}
        if(isdigit(exp[i])){
            int num=0;
            while(isdigit(exp[i])){
                num=num*10+(exp[i]-'0');
                i++;
            }
            push(num);
        }else{
            int b=pop();
            int a=pop();
            if(exp[i]=='+')push(a+b);
            else if(exp[i]=='-')push(a-b);
            else if(exp[i]=='*')push(a*b);
            else if(exp[i]=='/')push(a/b);
            i++;
        }
    }
    return pop();
}

int main(){
    char exp[100];
    fgets(exp,100,stdin);
    printf("%d",eval(exp));
    return 0;
}
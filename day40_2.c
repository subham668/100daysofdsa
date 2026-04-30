#include <stdio.h>

void dailyTemperatures(int t[],int n){
    int stack[100],top=-1;
    int ans[100]={0};

    for(int i=0;i<n;i++){
        while(top!=-1 && t[i]>t[stack[top]]){
            int idx=stack[top--];
            ans[idx]=i-idx;
        }
        stack[++top]=i;
    }

    for(int i=0;i<n;i++) printf("%d ",ans[i]);
}

int main(){
    int t[]={73,74,75,71,69,72,76,73};
    int n=8;
    dailyTemperatures(t,n);
    return 0;
}
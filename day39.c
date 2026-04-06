/*Problem Statement:
Implement a Min Heap using an array where the smallest element is always at the root.

Supported Operations:
- insert x
- extractMin
- peek

Input Format:
- First line contains integer N
- Next N lines contain heap operations

Output Format:
- Print results of extractMin and peek
- Print -1 if operation cannot be performed

Example:
Input:
6
insert 40
insert 10
insert 30
peek
extractMin
peek

Output:
10
10
30*/
#include<stdio.h>
#include<string.h>

int h[100],n=0;

void swap(int*a,int*b){int t=*a;*a=*b;*b=t;}

void heapify_up(int i){
while(i>0){
int p=(i-1)/2;
if(h[p]>h[i]){swap(&h[p],&h[i]);i=p;}
else break;
}
}

void heapify_down(int i){
while(1){
int l=2*i+1,r=2*i+2,small=i;
if(l<n && h[l]<h[small])small=l;
if(r<n && h[r]<h[small])small=r;
if(small!=i){swap(&h[i],&h[small]);i=small;}
else break;
}
}

void insert(int x){
h[n]=x;
heapify_up(n);
n++;
}

int extractMin(){
if(n==0)return -1;
int v=h[0];
h[0]=h[n-1];
n--;
heapify_down(0);
return v;
}

int peek(){
if(n==0)return -1;
return h[0];
}

int main(){
int N,x;
char op[20];
scanf("%d",&N);
while(N--){
scanf("%s",op);
if(strcmp(op,"insert")==0){scanf("%d",&x);insert(x);}
else if(strcmp(op,"extractMin")==0)printf("%d\n",extractMin());
else if(strcmp(op,"peek")==0)printf("%d\n",peek());
}
return 0;
}
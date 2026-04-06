/*
Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

Input:
- Postfix expression with operands and operators

Output:
- Print the integer result

Example:
Input:
2 3 1 * + 9 -

Output:
-4

Explanation:
Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.
*/
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

struct node{int data;struct node*next;}*top=NULL;

void push(int x){
struct node*n=(struct node*)malloc(sizeof(struct node));
if(n==NULL)return;
n->data=x;
n->next=top;
top=n;
}

int pop(){
if(top==NULL)return -1;
struct node*t=top;
int v=t->data;
top=top->next;
free(t);
return v;
}

int eval(char e[]){
int i=0;
while(e[i]){
if(e[i]==' '||e[i]=='\n'){i++;continue;}
if(isdigit(e[i])){
int n=0;
while(isdigit(e[i])){n=n*10+(e[i]-'0');i++;}
push(n);
}else{
int b=pop(),a=pop();
if(e[i]=='+')push(a+b);
else if(e[i]=='-')push(a-b);
else if(e[i]=='*')push(a*b);
else if(e[i]=='/')push(a/b);
i++;
}}
return pop();
}

int main(){
char e[100];
fgets(e,100,stdin);
printf("%d",eval(e));
return 0;
}
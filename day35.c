/*Problem: Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements)
- Second line: n space-separated integers

Output:
- Print queue elements from front to rear, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Use array and front/rear pointers. Enqueue inserts at rear, dequeue removes from front. Display from front to rear.*/
#include<stdio.h>
#include<stdlib.h>

struct node{int data;struct node*next;}*front=NULL,*rear=NULL;

void enqueue(int x){
struct node*n=(struct node*)malloc(sizeof(struct node));
n->data=x;n->next=NULL;
if(rear==NULL){front=rear=n;return;}
rear->next=n;rear=n;
}

void display(){
struct node*t=front;
while(t){printf("%d ",t->data);t=t->next;}
}

int main(){
int n,x,i;
scanf("%d",&n);
for(i=0;i<n;i++){scanf("%d",&x);enqueue(x);}
display();
return 0;
}
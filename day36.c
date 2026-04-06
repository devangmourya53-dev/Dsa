/*Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements to enqueue)
- Second line: n space-separated integers
- Third line: integer m (number of dequeue operations)

Output:
- Print queue elements from front to rear after operations, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
30 40 50 10 20

Explanation:
Use array and front/rear pointers. Rear wraps around to start after reaching array end. Dequeue removes elements from front. Display remaining elements in correct order.*/
#include<stdio.h>
#include<stdlib.h>

struct node{int data;struct node*next;}*front=NULL,*rear=NULL;

void enqueue(int x){
struct node*n=(struct node*)malloc(sizeof(struct node));
n->data=x;n->next=NULL;
if(rear==NULL){front=rear=n;return;}
rear->next=n;rear=n;
}

int dequeue(){
if(front==NULL)return -1;
struct node*t=front;
int v=t->data;
front=front->next;
if(front==NULL)rear=NULL;
free(t);
return v;
}

void display(){
struct node*t=front;
while(t){printf("%d ",t->data);t=t->next;}
}

int main(){
int n,x,m,i;
scanf("%d",&n);
for(i=0;i<n;i++){scanf("%d",&x);enqueue(x);}
scanf("%d",&m);
for(i=0;i<m;i++){
int v=dequeue();
enqueue(v);
}
display();
return 0;
}
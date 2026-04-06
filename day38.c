/*Problem: Deque (Double-Ended Queue)

A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.

Common Operations:
1. push_front(value): Insert an element at the front of the deque.
2. push_back(value): Insert an element at the rear of the deque.
3. pop_front(): Remove an element from the front of the deque.
4. pop_back(): Remove an element from the rear of the deque.
5. front(): Return the front element of the deque.
6. back(): Return the rear element of the deque.
7. empty(): Check whether the deque is empty.
8. size(): Return the number of elements in the deque.

Additional Operations:
- clear(): Remove all elements from the deque.
- erase(): Remove one or more elements from the deque.
- swap(): Swap contents of two deques.
- emplace_front(): Insert an element at the front without copying.
- emplace_back(): Insert an element at the rear without copying.
- resize(): Change the size of the deque.
- assign(): Replace elements with new values.
- reverse(): Reverse the order of elements.
- sort(): Sort the elements in ascending order.

Time Complexity:
- push_front, push_back, pop_front, pop_back, front, back, empty, size: O(1)
- clear, erase, resize, assign, reverse: O(n)
- sort: O(n log n)

Input:
- Sequence of deque operations with values (if applicable)

Output:
- Results of operations such as front, back, size, or the final state of the deque after all operations*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{int data;struct node*prev,*next;}*front=NULL,*rear=NULL;
int sz=0;

void push_front(int x){
struct node*n=(struct node*)malloc(sizeof(struct node));
n->data=x;n->prev=NULL;n->next=front;
if(front!=NULL)front->prev=n;
front=n;
if(rear==NULL)rear=n;
sz++;
}

void push_back(int x){
struct node*n=(struct node*)malloc(sizeof(struct node));
n->data=x;n->next=NULL;n->prev=rear;
if(rear!=NULL)rear->next=n;
rear=n;
if(front==NULL)front=n;
sz++;
}

void pop_front(){
if(front==NULL){printf("-1\n");return;}
struct node*t=front;
printf("%d\n",t->data);
front=front->next;
if(front!=NULL)front->prev=NULL;
else rear=NULL;
free(t);
sz--;
}

void pop_back(){
if(rear==NULL){printf("-1\n");return;}
struct node*t=rear;
printf("%d\n",t->data);
rear=rear->prev;
if(rear!=NULL)rear->next=NULL;
else front=NULL;
free(t);
sz--;
}

void get_front(){
if(front==NULL)printf("-1\n");
else printf("%d\n",front->data);
}

void get_back(){
if(rear==NULL)printf("-1\n");
else printf("%d\n",rear->data);
}

void empty(){
printf("%d\n",front==NULL);
}

void size(){
printf("%d\n",sz);
}

int main(){
int n,x;
char op[20];
scanf("%d",&n);
while(n--){
scanf("%s",op);
if(strcmp(op,"push_front")==0){scanf("%d",&x);push_front(x);}
else if(strcmp(op,"push_back")==0){scanf("%d",&x);push_back(x);}
else if(strcmp(op,"pop_front")==0)pop_front();
else if(strcmp(op,"pop_back")==0)pop_back();
else if(strcmp(op,"front")==0)get_front();
else if(strcmp(op,"back")==0)get_back();
else if(strcmp(op,"empty")==0)empty();
else if(strcmp(op,"size")==0)size();
}
return 0;
}
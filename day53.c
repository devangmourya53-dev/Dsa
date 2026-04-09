/*Problem Statement:
Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

Input Format:
- First line contains integer N (number of nodes)
- Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)

Output Format:
- Print nodes column by column from leftmost to rightmost vertical line

Example:
Input:
7
1 2 3 4 5 6 7

Output:
4
2
1 5 6
3
7

Explanation:
Vertical lines are formed based on horizontal distance from root. Nodes sharing the same distance are printed together.*/
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct QNode{
    struct Node* node;
    int hd;
};

struct Node* newNode(int data){
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=data;
    temp->left=temp->right=NULL;
    return temp;
}

struct Node* buildTree(int arr[],int n){
    if(n==0||arr[0]==-1) return NULL;
    struct Node** q=(struct Node**)malloc(n*sizeof(struct Node*));
    int f=0,r=0,i=1;
    struct Node* root=newNode(arr[0]);
    q[r++]=root;
    while(f<r&&i<n){
        struct Node* t=q[f++];
        if(i<n&&arr[i]!=-1){
            t->left=newNode(arr[i]);
            q[r++]=t->left;
        }
        i++;
        if(i<n&&arr[i]!=-1){
            t->right=newNode(arr[i]);
            q[r++]=t->right;
        }
        i++;
    }
    return root;
}

int main(){
    int n,i;
    scanf("%d",&n);
    int *arr=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++) scanf("%d",&arr[i]);

    struct Node* root=buildTree(arr,n);

    struct QNode* q=(struct QNode*)malloc(n*sizeof(struct QNode));
    int f=0,r=0;

    int *hd=(int*)malloc(n*sizeof(int));
    int *val=(int*)malloc(n*sizeof(int));
    int size=0;

    int min=0,max=0;

    q[r].node=root;
    q[r].hd=0;
    r++;

    while(f<r){
        struct QNode cur=q[f++];
        hd[size]=cur.hd;
        val[size]=cur.node->data;
        if(cur.hd<min) min=cur.hd;
        if(cur.hd>max) max=cur.hd;
        size++;

        if(cur.node->left){
            q[r].node=cur.node->left;
            q[r].hd=cur.hd-1;
            r++;
        }
        if(cur.node->right){
            q[r].node=cur.node->right;
            q[r].hd=cur.hd+1;
            r++;
        }
    }

    for(i=min;i<=max;i++){
        int j;
        for(j=0;j<size;j++){
            if(hd[j]==i){
                printf("%d",val[j]);
                int k;
                for(k=j+1;k<size;k++){
                    if(hd[k]==i){
                        printf(" %d",val[k]);
                    }
                }
                printf("\n");
                break;
            }
        }
    }
    return 0;
}
/*Problem Statement:
Perform zigzag (spiral) level order traversal of a binary tree. Alternate levels should be traversed left-to-right and right-to-left.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print traversal in zigzag order

Example:
Input:
7
1 2 3 4 5 6 7

Output:
1 3 2 4 5 6 7

Explanation:
Level 1 is printed left-to-right, level 2 right-to-left, and so on.*/
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data){
    struct Node* t=(struct Node*)malloc(sizeof(struct Node));
    t->data=data;
    t->left=t->right=NULL;
    return t;
}

struct Node* buildTree(int arr[],int n){
    if(n==0||arr[0]==-1) return NULL;
    struct Node** q=(struct Node**)malloc(n*sizeof(struct Node*));
    int f=0,r=0,i=1;
    struct Node* root=newNode(arr[0]);
    q[r++]=root;
    while(f<r&&i<n){
        struct Node* cur=q[f++];
        if(i<n&&arr[i]!=-1){
            cur->left=newNode(arr[i]);
            q[r++]=cur->left;
        }
        i++;
        if(i<n&&arr[i]!=-1){
            cur->right=newNode(arr[i]);
            q[r++]=cur->right;
        }
        i++;
    }
    return root;
}

int main(){
    int n,i;
    scanf("%d",&n);
    int* arr=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++) scanf("%d",&arr[i]);

    struct Node* root=buildTree(arr,n);

    struct Node** q=(struct Node**)malloc(n*sizeof(struct Node*));
    int f=0,r=0;

    q[r++]=root;
    int leftToRight=1;

    while(f<r){
        int size=r-f;
        int* temp=(int*)malloc(size*sizeof(int));
        int k=0;

        int j;
        for(j=0;j<size;j++){
            struct Node* cur=q[f++];
            temp[k++]=cur->data;

            if(cur->left) q[r++]=cur->left;
            if(cur->right) q[r++]=cur->right;
        }

        if(leftToRight){
            for(j=0;j<k;j++){
                printf("%d",temp[j]);
                if(f<r||j<k-1) printf(" ");
            }
        }else{
            for(j=k-1;j>=0;j--){
                printf("%d",temp[j]);
                if(f<r||j>0) printf(" ");
            }
        }

        leftToRight=!leftToRight;
        free(temp);
    }
    return 0;
}
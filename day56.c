/*Problem Statement:
Check whether a given binary tree is symmetric around its center.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print YES if symmetric, otherwise NO

Example:
Input:
7
1 2 2 3 4 4 3

Output:
YES

Explanation:
Left subtree is a mirror image of the right subtree.*/
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

int isMirror(struct Node* a,struct Node* b){
    if(a==NULL&&b==NULL) return 1;
    if(a==NULL||b==NULL) return 0;
    if(a->data!=b->data) return 0;
    return isMirror(a->left,b->right)&&isMirror(a->right,b->left);
}

int main(){
    int n,i;
    scanf("%d",&n);
    int* arr=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++) scanf("%d",&arr[i]);

    struct Node* root=buildTree(arr,n);

    if(isMirror(root,root)) printf("YES");
    else printf("NO");
    return 0;
}
/*Problem Statement:
Given a queue of integers, reverse the queue using a stack.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers

Output Format:
- Print the reversed queue

Example:
Input:
5
10 20 30 40 50

Output:
50 40 30 20 10*/
#include<stdio.h>

int main(){
int n;
scanf("%d",&n);
int q[n],s[n],i,top=-1;
for(i=0;i<n;i++)scanf("%d",&q[i]);
for(i=0;i<n;i++)s[++top]=q[i];
for(i=0;i<n;i++)q[i]=s[top--];
for(i=0;i<n;i++)printf("%d ",q[i]);
return 0;
}
/*Problem Statement
Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.

Input Format
An integer array arr[].

Output Format
Print the length of the longest subarray with sum equal to zero.

Sample Input
15 -2 2 -8 1 7 10 23

Sample Output
5

Explanation
The subarray [-2, 2, -8, 1, 7] has a sum of 0 and is the longest such subarray.*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 100000
typedef struct{int key,val;}Node;
Node h[MAX];
int used[MAX];
int find(int key){
int i=abs(key)%MAX;
while(used[i]&&h[i].key!=key)i=(i+1)%MAX;
return i;
}
int main(){
int n;
scanf("%d",&n);
int a[n];
for(int i=0;i<n;i++)scanf("%d",&a[i]);
int sum=0,max=0;
for(int i=0;i<MAX;i++)used[i]=0;
int idx=find(0);
h[idx].key=0;
h[idx].val=-1;
used[idx]=1;
for(int i=0;i<n;i++){
sum+=a[i];
int j=find(sum);
if(!used[j]){
h[j].key=sum;
h[j].val=i;
used[j]=1;
}else{
int len=i-h[j].val;
if(len>max)max=len;
}
}
printf("%d",max);
return 0;
}
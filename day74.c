/*Problem Statement
Given an array of candidate names where each name represents a vote cast for that candidate, determine the candidate who received the maximum number of votes. In case of a tie, return the lexicographically smallest candidate name.

Input Format
First line contains an integer n representing number of votes.
Second line contains n space-separated strings representing candidate names.

Output Format
Print the name of the winning candidate followed by the number of votes received.

Sample Input
13
john johnny jackie johnny john jackie jamie jamie john johnny jamie johnny john

Sample Output
john 4

Explanation
Both john and johnny receive 4 votes, but john is lexicographically smaller, so john is declared the winner.*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void*a,const void*b){
return strcmp((char*)a,(char*)b);
}
int main(){
int n;
scanf("%d",&n);
char a[n][100];
for(int i=0;i<n;i++)scanf("%s",a[i]);
qsort(a,n,sizeof(a[0]),cmp);
int max=1,c=1;
char res[100];
strcpy(res,a[0]);
for(int i=1;i<n;i++){
if(strcmp(a[i],a[i-1])==0)c++;
else c=1;
if(c>max){
max=c;
strcpy(res,a[i]);
}
}
printf("%s %d",res,max);
return 0;
}
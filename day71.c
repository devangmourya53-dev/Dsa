/*Problem Statement
Implement a hash table using quadratic probing with formula:

h(k, i) = (h(k) + i*i) % m

Input Format
Same as previous.

Output Format
Result of SEARCH operations.

Sample Input
7
4
INSERT 49
INSERT 56
SEARCH 49
SEARCH 15

Sample Output
FOUND
NOT FOUND

Explanation
Collisions resolved using i² jumps.*/
#include<stdio.h>
#include<string.h>
#define SIZE 1000
int table[SIZE];
int m;
int hash(int k){return k%m;}
void insert(int k){
for(int i=0;i<m;i++){
int idx=(hash(k)+i*i)%m;
if(table[idx]==-1){
table[idx]=k;
return;
}
}
}
int search(int k){
for(int i=0;i<m;i++){
int idx=(hash(k)+i*i)%m;
if(table[idx]==-1)return 0;
if(table[idx]==k)return 1;
}
return 0;
}
int main(){
scanf("%d",&m);
for(int i=0;i<m;i++)table[i]=-1;
int q;
scanf("%d",&q);
while(q--){
char op[10];
int x;
scanf("%s%d",op,&x);
if(strcmp(op,"INSERT")==0)insert(x);
else if(strcmp(op,"SEARCH")==0){
if(search(x))printf("FOUND\n");
else printf("NOT FOUND\n");
}
}
return 0;
}
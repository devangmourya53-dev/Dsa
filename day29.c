/*Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer k

Output:
- Print the linked list elements after rotation, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
40 50 10 20 30

Explanation:
Connect last node to head forming circular list. Traverse to (n-k)th node, set next to NULL, update head to (n-k+1)th node.*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, k;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    // Read number of nodes
    scanf("%d", &n);

    // Create linked list
    for(int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Read k
    scanf("%d", &k);

    if(head == NULL || k == 0)
        return 0;

    // Find length and last node
    int length = 1;
    temp = head;

    while(temp->next != NULL) {
        temp = temp->next;
        length++;
    }

    // Make circular
    temp->next = head;

    // Effective rotations
    k = k % length;

    int steps = length - k;

    struct Node* newTail = head;

    for(int i = 1; i < steps; i++)
        newTail = newTail->next;

    struct Node* newHead = newTail->next;

    newTail->next = NULL;

    // Print rotated list
    temp = newHead;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
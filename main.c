//
//  main.c
//  CheckCycle
//
//  Created by NAKHOE KIM on 12/10/15.
//  Copyright © 2015 NAKHOE KIM. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Node{
    struct Node *next;
    int value;
}Node;
/*
-Make slow pointer and fast pointer-
slow pointer starts at the head
fast pointer starts at the next of head
if fast gets to the NULL
    return true;
else if fast == slow or fast->next ==slow
    return true;
else 
   slow = slow->next;
   fast = fast->next->next;
 */
bool CheckCycle(Node *head){
    Node *slow, *fast;
    slow = head;
    fast = head->next;
    while(true)
    {
        if(!fast|| !fast->next){
            printf("acyclic\n");
            return true;
        }
        else if (fast == slow || fast->next == slow){
            printf("Cyclic\n");
            return true;
        }
        else{
            slow = slow->next;
            fast = fast->next->next;
        }
    }
    return true;
}
bool InsertInfront(Node **head, int data)
{
    if(!head || !*head) return false;
    Node *newElem = malloc(sizeof(Node));
    if (!newElem) return false;
    newElem->value = data;
    newElem->next = *head;
    *head = newElem;
    return true;
}
bool traverse(Node **head){
    Node *elem = *head;
    while(elem != NULL){
        printf("%d -> ", elem->value);
        elem = elem->next;
    }
    printf("NULL\n");
    return true;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    Node *root = malloc(sizeof(Node));
    InsertInfront(&root, 4);
    InsertInfront(&root, 3);
    InsertInfront(&root, 2);
    InsertInfront(&root, 1);
    traverse(&root);
    CheckCycle(root);
    Node a = {0,1};
    Node b = {0,2};
    Node c = {0,3};
    Node d = {0,4};
    Node e = {0,5};
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &c;
    Node *head = &a;
    CheckCycle(head);
    
}

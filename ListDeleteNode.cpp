#include <bits/stdc++.h>

using namespace std;

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
 
 /* Assume positon is valid */
SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* head, int position) {
    if (head == NULL)
        return  NULL;
    if (position == 0)
        return head->next;

    SinglyLinkedListNode *prev = head;
    SinglyLinkedListNode *ptr = head->next;

    int counter = 1;
    while (counter < position) {
        ptr = ptr->next;
        prev = prev->next;
        counter++;
    }

    prev->next = ptr->next;

    return head;
}

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* reverse(SinglyLinkedListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    SinglyLinkedListNode *prev = NULL;
    SinglyLinkedListNode *p = head;
    SinglyLinkedListNode *new_p;

    while (p != NULL) {    
        new_p = p->next;
        p->next = prev;
        prev = p;
        p = new_p;
    }

    return prev;
}

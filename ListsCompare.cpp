/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
bool compare_lists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode *p1 = head1;
    SinglyLinkedListNode *p2 = head2;

    while (p1 != NULL || p2 != NULL) {
        if ((p1 == NULL && p2 != NULL) || 
            (p1 != NULL && p2 == NULL) ||
            (p1->data != p2->data)) {
                return false;
            } 

        p1 = p1->next;
        p2 = p2->next;
    }
    return true;
}

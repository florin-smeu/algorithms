/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
void reversePrint(SinglyLinkedListNode* head) {
    if (head == NULL) {
        return;
    } 

    SinglyLinkedListNode *p = head;
    int len = 0;
    while (p != NULL) {
        p = p->next;
        len++;
    }

    while (len > 0) {
        p = head;
        int pos = len - 1;
        while (pos > 0) {
            p = p->next;
            pos--;
        }
        cout << p->data << endl;
        len--;
    }
}

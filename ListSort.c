/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode *sortedMerge(struct ListNode *it1, struct ListNode *it2) {
    struct ListNode *ans = NULL;
    
    if (!it1)
        return it2;
    else if (!it2)
        return it1;
    
    
    if (it1->val <= it2->val) {
        ans = it1;
        ans->next = sortedMerge(it1->next, it2);
    } else {
        ans = it2;
        ans->next = sortedMerge(it1, it2->next);
    }
    
    return ans;
}

void split(struct ListNode *it, struct ListNode **it1, struct ListNode **it2) {
    struct ListNode *fast;
    struct ListNode *slow;
    slow = it;
    fast = it->next;
    
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    
    *it1 = it;
    *it2 = slow->next;
    slow->next = NULL;
}

void mergeSort(struct ListNode** h) {
    struct ListNode *it = *h;
    struct ListNode *it1;
    struct ListNode *it2;
    
    if (it == NULL || it->next == NULL)
        return;
    
    split(it, &it1, &it2);
    
    mergeSort(&it1);
    mergeSort(&it2);
    
    *h = sortedMerge(it1, it2);
}

struct ListNode* sortList(struct ListNode* head){
    mergeSort(&head);
    return head;
}

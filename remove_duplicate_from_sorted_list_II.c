struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->val = -1;
    dummy->next = head;
    struct ListNode *prev = dummy, *curr = head;    
    while (curr != NULL) {
        while (curr->next != NULL && curr->val == curr->next->val) {
            curr = curr->next;
        }
        if (prev->next == curr) {
            prev = prev->next;
        } else {
            prev->next = curr->next;
        }
        curr = curr->next;
    }
    struct ListNode* result = dummy->next;
    free(dummy);
    return result;
}
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    if (head == NULL || left == right) return head;
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode* pre = dummy;
    for (int i = 1; i < left; i++) {
        pre = pre->next;
    }
    struct ListNode* current = pre->next;
    for (int i = left; i < right; i++) {
        struct ListNode* nextNode = current->next;
        current->next = nextNode->next;
        nextNode->next = pre->next;
        pre->next = nextNode;
    }
    return dummy->next;
}
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *prev = NULL, *temp = head, *nextNode = NULL;
    while (temp != NULL) {
        nextNode = temp->next;
        temp->next = prev;
        prev = temp;
        temp = nextNode;
    }
    head = prev;   
    return head;
}
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode *front = head;
    struct ListNode *back = head;

    while (back != NULL && back->next != NULL) {
        front = front->next;
        back = back->next->next;
    }

    return front;
}
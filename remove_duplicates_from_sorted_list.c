struct ListNode* deleteDuplicates(struct ListNode* head){
    
    struct ListNode* current = head;
    struct ListNode* new_list = head;

    
    while(current !=NULL && current->next!=NULL)
    {
        if(current->val == current->next->val)
        {
            current->next = current->next->next;
}
        else
        {
            current=current->next;
        }
    }
    
    return new_list;
}
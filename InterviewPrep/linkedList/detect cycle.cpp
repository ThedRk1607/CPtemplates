
 ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return NULL;
    
        ListNode *slow  = head;
        ListNode *fast  = head;
        ListNode *entry = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {                      
                while(slow != entry) {               
                    slow  = slow->next;
                    entry = entry->next;
                }
                return entry;
            }
        }
        return NULL;      
    }

//utility function to create cycle
void createCycle(node* &head,int a,int b) {
    int cnta = 0,cntb = 0;
    node* p1 = head;
    node* p2 = head;
    while(cnta != a || cntb != b) {
        if(cnta != a) p1 = p1->next, ++cnta;
        if(cntb != b) p2 = p2->next, ++cntb;
    }
    p2->next = p1;
}

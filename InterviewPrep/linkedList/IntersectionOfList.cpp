
//bruteForce
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        while(headA!=NULL){
            ListNode*currB=headB;
            while(currB!=NULL){
                if(headA==currB){
                    cout<<"Intersection at ";
                    return currB;
                }
                currB=currB->next;
            }
            headA=headA->next;
        }
        cout<<"No intersection\n";
        return NULL;
        
    }

//using set;
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       
        set<ListNode*>st;
        
        while(headA!=NULL){
            st.insert(headA);
            headA=headA->next;
        }

        while(headB!=NULL){
            if(st.find(headB)!=st.end()){
                cout<<"Intersected at ";
                return headB;
            }
            headB=headB->next;
        }

        cout<<"No intersection\n";
        return NULL;
    }

//usint two pointer;
node* intersectionPresent(node* head1,node* head2) {
    while(head2 != NULL) {
        node* temp = head1;
        while(temp != NULL) {
            //if both nodes are same
            if(temp == head2) return head2;
            temp = temp->next;
        }
        head2 = head2->next;
    }
    //intersection is not present between the lists return null
    return NULL;
}

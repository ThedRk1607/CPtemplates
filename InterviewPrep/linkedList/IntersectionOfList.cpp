
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
ListNode * getIntersectionNode(ListNode * headA, ListNode * headB) {
  ListNode * pA = headA;
  ListNode * pB = headB;
  while (pA != pB) {
    pA = pA == nullptr ? headB : pA -&gt; next;
    pB = pB == nullptr ? headA : pB -&gt; next;
  }
  return pA;
}

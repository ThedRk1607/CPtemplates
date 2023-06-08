//using stack;
 bool isPalindrome(ListNode* head) {
         ListNode*curr=head;
         stack<int>s;
         while(curr!=NULL){
             s.push(curr->val);
             curr=curr->next;
         }
    bool ok=true;
         while(head!=NULL){
             int x=s.top();
             s.pop();
             if(x!=head->val)ok=false;
             head=head->next;
         }

         if(ok)return true;
         return false;
    }


class Solution {
public:
    void push(int data,ListNode**head)
    {
       ListNode* temp = new ListNode(data);
      
        temp->next = *head;
        *head = temp;
    }


    ListNode*reverseList(ListNode*head){
	ListNode*newHead=NULL;
	while(head!=NULL){
		ListNode*next=(head)->next;
		(head)->next=newHead;
		newHead=head;
		head=next;
	}

	return newHead;
}

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*curr1=l1;
        ListNode*curr2=l2;
        ListNode*res=NULL;
        int c=0;
        while(curr1!=NULL and curr2!=NULL){
            int sum=(curr1->val)+(curr2->val);
             
            if(sum>9){
                
                push(sum%10+c,&res);
                c=1;
            }else {
                push((sum+c)%10,&res);
                if(sum+c>9)c=1;
                else c=0;
            }

            curr1=curr1->next;
            curr2=curr2->next;
        }

        while(curr1!=NULL){
            int sum=curr1->val;
            if(sum>9){
                push(sum%10+c,&res);
                c=1;
            }else {
                push((sum+c)%10,&res);
                if(sum+c>9)c=1;
                else c=0;
            }
            curr1=curr1->next;
        }
        
        while(curr2!=NULL){
             int sum=curr2->val;
            if(sum>9){
                push(sum%10+c,&res);
                c=1;
            }else {
                push((sum+c)%10,&res);
                if(sum+c>9)c=1;
                else c=0;
            }
            curr2=curr2->next;
        }
        if(c==1)push(1,&res);
        return reverseList(res);

    }
};
Console

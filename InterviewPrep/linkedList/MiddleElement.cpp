
int MiddleElement(ListNode*head){
	  ListNode*curr=head;
	  ListNode*slow=head;
	  ListNode*fast=head;
	  while(fast->next!=NULL){
	  	slow=slow->next;
	  	if(fast->next->next!=NULL)fast=fast->next->next;
	  	else fast=fast->next;
	  }

	  return slow->val;

	
}

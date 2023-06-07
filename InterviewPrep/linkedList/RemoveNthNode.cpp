
ListNode* removeNthNode(ListNode*head,int n){
	ListNode*curr=head;
  //make difference of n between them
	ListNode*fast=curr;
	ListNode*slow=curr;

	for(int i=1;i<=n;i++)fast=fast->next;
		while(fast->next!=NULL){
			fast=fast->next;
			slow=slow->next;
		}
		slow->next=slow->next->next;
		return curr->next;
	
}

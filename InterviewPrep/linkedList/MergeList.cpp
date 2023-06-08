
ListNode*MergeList(ListNode*head1,ListNode*head2){
	ListNode*curr1=head1;
	ListNode*curr2=head2;
	ListNode*Merge=NULL;
	while(curr1!=NULL and curr2!=NULL){
		if((curr1->val)<(curr2->val))push(curr1->val,&Merge),curr1=curr1->next;
		else push(curr2->val,&Merge),curr2=curr2->next;;

		
		
	}

	while(curr1!=NULL){
		push(curr1->val,&Merge);
		curr1=curr1->next;
	}
	while(curr2!=NULL){
		push(curr2->val,&Merge);
		curr2=curr2->next;
	}

	return Merge;
}

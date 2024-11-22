//bst traversal
	node*findval(node*cur,int x){
		if(cur->val==x)return cur;
		else if(x>cur->val)return findval(cur->right);
		else findval(cur->left);
	}


	//check bst
	bool isBst=true;
	pair<int,int>check(node*cur){
		if(cur==NULL)return {INF,-INF};
		pii Lint=check(cur->left);
		pii Rint=check(cur->right);
		if(cur->val<=Lint.S)isBst=false;
		if(cur->val>=Rint.F)isBst=false;
		return {min(cur->val,Lint.F),max(cur->val,Rint.S)};
	}
//check bbst
	int check(node*cur){
		if(cur==NULL)return 0;
		int lht=check(cur->left);
		int rht=check(cur->right);

		if(abs(lht-rht)>1)isbst=false;
		return max(lht,rht)+1;
	}

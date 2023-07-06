
int insertIntoBst(TreeNode*root,int val){
	if(root==NULL)return new TreeNode(val);
	TreeNode*cur=root;
	while(true){
		if(cur->val<=val){
			if(cur->right!=null)curr=curr->right;
			else {
				cur->right=new TreeNode(val);
				break;
			}
		}else {
			if(cur->left!=NULL)curr=curr->left;
			else {
				cur->left=new TreeNode(val);
				break;
			}
		}
	}
	return root;
}

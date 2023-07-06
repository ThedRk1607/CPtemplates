
int findceil(TreeNode *root,int key){
  int ceil=-1;
  //using binary search;

  while(root){
    if(root->data==key){
      ceil=root->data;
      return ceil;
    }else (root->data<k){
        root=root->right;

      }else {
      ceil=root->data;
      root=root->left;
    }
  }
}


int ht(TreeNode*root){
        if(root==NULL)return 0;
        return 1+max(ht(root->left),ht(root->right));
        
    }
     
    bool isBalanced(TreeNode* root) {
        if(root==NULL)return true;
        int lr=ht(root->left);
        int hr=ht(root->right);
       
    if(abs(lr-hr)<=1 and isBalanced(root->left) and isBalanced(root->right))return true;
        return false;

    }

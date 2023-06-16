
int ht(TreeNode*root,int& d){
        if(root==NULL)return 0;
        int lr=ht(root->left,d);
        int hr=ht(root->right,d);
        d=max(d,lr+hr);
        return 1+max(lr,hr);
    }
    int diameterOfBinaryTree(TreeNode* root) {
       int dia=0;
       ht(root,dia);
       return dia;
    }

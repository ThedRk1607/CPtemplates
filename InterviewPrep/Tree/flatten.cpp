class Solution {
public:
    TreeNode*node=NULL;
    void flatten(TreeNode* root) {
       if(!root)return ;
        flatten(root->right);
       flatten(root->left);
      
     root->right=node;
     root->left=NULL;
        node=root;


    }
};

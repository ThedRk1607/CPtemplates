
class Solution {
public:
    bool f(TreeNode*root1,TreeNode*root2){
        if(!root1) return !root2;
        if(!root2)return !root1;
        return ((root1->val==root2->val) and f(root1->left,root2->right) and f(root1->right,root2->left));
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)return true;
        return f(root->left,root->right);
    }
};

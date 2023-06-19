
class Solution {
public:
    void rec(TreeNode*root,int level,vector<int>&res){
        if(root==NULL)return;
        if(level==res.size())res.push_back(root->val);
        rec(root->right,level+1,res);
        rec(root->left,level+1,res);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
       
        rec(root,0,res);
        return res;
    }
};


class Solution {
public:
     void dfs(TreeNode*root,int &count,int &res,int k){
         if(root==NULL)return;
         dfs(root->left,count,res,k);
        count++;
        if(count==k){
            res=root->val;
            return ;
        }
         dfs(root->right,count,res,k);
     }
    int kthSmallest(TreeNode* root, int k) {
        int res=-1;
        int count=0;
        dfs(root,count,res,k);
        return res;
    }
};

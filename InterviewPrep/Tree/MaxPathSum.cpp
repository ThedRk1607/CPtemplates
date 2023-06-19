
int maxPath(TreeNode*root,int &ans){
        if(root==NULL)return 0;
        int l=max(0,maxPath(root->left,ans));
        int r=max(0,maxPath(root->right,ans));
        int val=root->val;
        ans=max(ans,l+r+val);
        return max(l,r)+val;
    }
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        maxPath(root,ans);
        return ans;
    }

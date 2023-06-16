
void solve(vector<int>&ans,TreeNode*root){
        TreeNode*node=root;
        stack<TreeNode*>st;
        while(1){
            if(node!=NULL){
                st.push(node);
                node=node->left;
            }else {
                if(st.empty()==true)break;
                node=st.top();
                st.pop();
                ans.push_back(node->val);
                    node=node->right;
            }
        }

    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        solve(ans,root);
        return ans;

    }

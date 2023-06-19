
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
         vector<vector<int>>ans;
        if(root==NULL)return ans;
       
        queue<TreeNode*>q;
        q.push(root);
        int leftToright=1;

        while(!q.empty()){
           
            int sz=q.size();
            vector<int>level(sz);
            for(int i=0;i<sz;i++){
                 TreeNode*tmp=q.front();
                   q.pop();
                int idx=(leftToright==1) ? i : sz-i-1;
                level[idx]=tmp->val;
                if(tmp->left)q.push(tmp->left);
                if(tmp->right)q.push(tmp->right);
               
            }
             ans.push_back(level);
            leftToright^=1;
        }
        return ans;
    }
};

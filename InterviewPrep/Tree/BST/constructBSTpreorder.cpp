
class Solution {
public:
    TreeNode*build(vector<int>&preorder,int &idx,int mn,int mx){
        
        if(idx>=preorder.size())return NULL;
        int cur=preorder[idx];
        if(cur<mn or cur>mx)return NULL;
        TreeNode* newNode = new TreeNode(cur);
        idx++;
        newNode->left=build(preorder,idx,mn,cur);
        newNode->right=build(preorder,idx,cur,mx);
        return newNode;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx=0;
        return build(preorder,idx,INT_MIN,INT_MAX);
    }
};

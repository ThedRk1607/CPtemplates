
class Solution {
public:
    bool isValidBSTUtil(TreeNode* node, TreeNode* minNode, TreeNode* maxNode) {
        if (node == nullptr) {
            return true;
        }

        if ((minNode != nullptr && node->val <= minNode->val) ||
            (maxNode != nullptr && node->val >= maxNode->val)) {
            return false;
        }

        return isValidBSTUtil(node->left, minNode, node) &&
               isValidBSTUtil(node->right, node, maxNode);
    }

   bool isvalid(TreeNode*root,TreeNode*mn,TreeNode*mx){
      return isValidBSTUtil(root,NULL,NULL);
    }
};

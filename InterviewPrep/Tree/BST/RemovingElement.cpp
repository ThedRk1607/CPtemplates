
class Solution {
public:
   int getmin(TreeNode*root){
       if(root->left==NULL)return root->val;
       else return getmin(root->left);
   }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr)
        return root;

    if (key < root->val)
        root->left = deleteNode(root->left, key);
    else if (key > root->val)
        root->right = deleteNode(root->right, key);
    else {
        // Case 1: Node is a leaf node
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            root = nullptr;
        }
        // Case 2: Node has only one child
        else if (root->left == nullptr) {
            TreeNode* temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == nullptr) {
            TreeNode* temp = root;
            root = root->left;
            delete temp;
        }
        // Case 3: Node has two children
        else {
            int mn = getmin(root->right);
            root->val = mn;
            root->right = deleteNode(root->right, mn);
        }
    }

    return root;
        }
    
};

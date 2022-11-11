/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
TreeNode* searchBST(TreeNode* root, int val) {
        if (root != nullptr){
            if (root->val > val) {
                return searchBST(root->left, val);
            }
            if(root->val < val){
                return searchBST(root->right, val);
            }
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
            //FIND TARGET KEY
        if(searchBST(root, key) != NULL){
            if (root->val > key) {
                root->left = deleteNode(root->left, key);
            }
            else if(root->val < key){
                root->right = deleteNode(root->right, key);
            }
            else {
                //CASE FOR NO CHILD
                if (!root->right && !root->left){
                    return NULL;
                }
                //CASE FOR ONE CHILD
                else if (!root->right || !root->left){
                    return right ? root->right : root->left;
                }
                //CASE FOR TWO CHILD
                else {
                    TreeNode* temp = root->left;
                    while(temp->right!=NULL) temp = temp->right;
                    root->val = temp->val;
                    root->left = deleteNode(root->left, temp->val);
                }
            }
        }
        return root;
    }
};

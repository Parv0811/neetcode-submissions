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
    int heightOfNode(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        return max(heightOfNode(root->left),heightOfNode(root->right))+1;

    }
public:
    bool isBalanced(TreeNode* root) {

        if(root==nullptr){
            return true;
        }
        
        if(abs(heightOfNode(root->left)-heightOfNode(root->right))>1){
            return false;
        }
        return (isBalanced(root->left) && isBalanced(root->right));
    
    }    
};

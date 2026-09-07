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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || !p || !q){
            return nullptr;
        
        }
        TreeNode* curr = root;

        while(curr){
            int a = p->val;
            int b = q->val;
            int c = curr->val;
            if(p->val<curr->val && q->val<curr->val){
                curr = curr->left;
            }
            else if(a>c && b>c){
                curr = curr->right;
            }
            else{
                return curr;
            }

        }
        return nullptr;
    }
};

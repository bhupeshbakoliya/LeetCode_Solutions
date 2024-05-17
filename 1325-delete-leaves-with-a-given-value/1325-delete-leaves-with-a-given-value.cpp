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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
                if (!root) return nullptr;

        // Recursively remove leaf nodes from the left and right subtrees.
        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);

        // After removing from subtrees, check if the current node is a leaf with the target value.
        if (!root->left && !root->right && root->val == target) {
            // If it is, delete the node by returning null.
            return nullptr;
        }

        // Otherwise, return the current node.
        return root;
    }


        
        
    };

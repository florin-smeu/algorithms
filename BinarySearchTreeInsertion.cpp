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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *new_node = new TreeNode(val);
        if (root == NULL) {
            return new_node;
        }
        
        TreeNode *p = root;
        while (true) {
            if (p->left != NULL && val < p->val) {
                p = p->left;
                continue;
            }
            if (p->right != NULL && val > p->val) {
                p = p->right;
                continue;
            }
            break;
        }
        
        if (val < p->val) {
            p->left = new_node;
        } else {
            p->right = new_node;
        }

        return root;
    }
};

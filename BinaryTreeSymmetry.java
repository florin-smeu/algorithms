/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    boolean isMirror(TreeNode node1, TreeNode node2) {
        if (node1 == null && node2 == null) {
            return true;
        }
        
        if (node1 != null && node2 != null && node1.val == node2.val) {
            boolean extIsMirror = isMirror(node1.left, node2.right);
            boolean intIsMirror = isMirror(node1.right, node2.left);
            
            return extIsMirror && intIsMirror;
        }
        
        return false;
    }
    
    public boolean isSymmetric(TreeNode root) {
        return isMirror(root, root);
    }
}

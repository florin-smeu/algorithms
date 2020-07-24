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
class QueueEntry {
    TreeNode node;
    int level;
    
    QueueEntry() {
        
    }
    
    QueueEntry(TreeNode node, int level) {
        this.node = node;
        this.level = level;
    }
}

class Solution {
    public int computeHeight(TreeNode node, int acc) {
        if (node == null) {
            return acc;
        }
        int h1 = computeHeight(node.left, acc + 1);
        int h2 = computeHeight(node.right, acc + 1);
        if (h1 > h2) {
            return h1;
        }
        return h2;
    }
    
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        int height = computeHeight(root, 0);
        if (height == 0) {
            return ans;
        }
        
        for (int i = 0; i < height; ++i) {
            ans.add(new ArrayList<Integer>());
        }
        
        Queue<QueueEntry> q = new LinkedList<>();
        q.offer(new QueueEntry(root, 0));
        
        while(!q.isEmpty()) {
            QueueEntry crt = q.poll();
            
            ans.get(crt.level).add(crt.node.val);
            
            if (crt.node.left != null) {
                q.offer(new QueueEntry(crt.node.left, crt.level + 1));
            }
            if (crt.node.right != null) {
                q.offer(new QueueEntry(crt.node.right, crt.level + 1));
            }
        }
                    
        return ans;
    }
}

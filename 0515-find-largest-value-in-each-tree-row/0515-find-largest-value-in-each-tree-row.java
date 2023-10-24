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
    public List<Integer> largestValues(TreeNode root) {
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        List<Integer> values = new ArrayList<Integer>();
        
        if(root != null) q.offer(root);
        
        while(!q.isEmpty()) {
            int max = Integer.MIN_VALUE, n = q.size();
            for(int i = 0; i < n; i++) {
                TreeNode node = q.poll();
                max = Math.max(max, node.val);
                if(node.left != null) q.offer(node.left);
                if(node.right != null) q.offer(node.right);
            }
            values.add(max);
        }
        
        return values;
    }
}
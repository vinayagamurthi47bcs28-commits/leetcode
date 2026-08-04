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
    private int maxPathSum = Integer.MIN_VALUE;

    public int maxPathSum(TreeNode root) {
        maxGain(root);
        return maxPathSum;
    }

    private int maxGain(TreeNode node) {
        if (node == null) return 0;

        // Recursively get the max sum from left and right subtrees.
        // If the path sum is negative, ignore it by taking Math.max(..., 0).
        int leftGain = Math.max(maxGain(node.left), 0);
        int rightGain = Math.max(maxGain(node.right), 0);

        // Price of the path passing through the current node as the highest peak
        int currentPathSum = node.val + leftGain + rightGain;

        // Update the global maximum path sum found so far
        maxPathSum = Math.max(maxPathSum, currentPathSum);

        // For the parent node's recursive call, return the maximum single-branch gain
        return node.val + Math.max(leftGain, rightGain);
    }
}

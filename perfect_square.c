class Solution {
    public int numSquares(int n) {
        int[] dp = new int[n + 1];
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            int minSquares = Integer.MAX_VALUE;
            for (int j = 1; j * j <= i; j++) {
                minSquares = Math.min(minSquares, dp[i - j * j] + 1);
            }
            dp[i] = minSquares;
        }
        return dp[n];
    }
}

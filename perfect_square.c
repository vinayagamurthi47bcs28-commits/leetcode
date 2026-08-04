class Solution {
    public int numSquares(int n) {
        // dp[i] will store the least number of perfect square numbers that sum to i
        int[] dp = new int[n + 1];
        
        // Base case: dp[0] = 0 (0 requires 0 squares)
        dp[0] = 0;
        
        // Fill the dp array from 1 to n
        for (int i = 1; i <= n; i++) {
            int minSquares = Integer.MAX_VALUE;
            
            // Try subtracting every perfect square j*j less than or equal to i
            for (int j = 1; j * j <= i; j++) {
                minSquares = Math.min(minSquares, dp[i - j * j] + 1);
            }
            
            dp[i] = minSquares;
        }
        
        return dp[n];
    }
}

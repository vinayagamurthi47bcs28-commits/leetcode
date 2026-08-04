class Solution {
    public int maxProfit(int[] prices) {
        if (prices == null || prices.length == 0) return 0;

        // Initialize state variables
        int buy1 = Integer.MIN_VALUE;
        int sell1 = 0;
        int buy2 = Integer.MIN_VALUE;
        int sell2 = 0;

        for (int price : prices) {
            // Max profit after buying the 1st stock (negative cash flow)
            buy1 = Math.max(buy1, -price);
            // Max profit after selling the 1st stock
            sell1 = Math.max(sell1, buy1 + price);
            // Max profit after buying the 2nd stock
            buy2 = Math.max(buy2, sell1 - price);
            // Max profit after selling the 2nd stock
            sell2 = Math.max(sell2, buy2 + price);
        }

        return sell2;
    }
}

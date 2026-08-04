class Solution {
    public int divide(int dividend, int divisor) {
        if (dividend == Integer.MIN_VALUE && divisor == -1) {
            return Integer.MAX_VALUE;
        }

        // 2. Track if the final answer should be negative
        boolean isNegative = (dividend < 0) ^ (divisor < 0);

        // 3. Force both numbers to be NEGATIVE to avoid overflow
        if (dividend > 0) dividend = -dividend;
        if (divisor > 0) divisor = -divisor;

        int quotient = 0;

        // 4. Repeated multiplication using addition
        // Since numbers are negative, -43 <= -3 means we still have room to divide
        while (dividend <= divisor) {
            int tempDivisor = divisor;
            int multiple = 1;

            // Double the divisor using addition (tempDivisor + tempDivisor)
            // We stop if doubling would overflow past Integer.MIN_VALUE
            while (tempDivisor >= Integer.MIN_VALUE - tempDivisor && dividend <= tempDivisor + tempDivisor) {
                tempDivisor = tempDivisor + tempDivisor; // Multiplied by 2!
                multiple = multiple + multiple;         // Multiplied by 2!
            }

            // Subtract the chunk from the dividend and save the count
            dividend -= tempDivisor;
            quotient += multiple;
        }

        // 5. Apply the correct sign and return the truncated answer
        return isNegative ? -quotient : quotient;
    }
}

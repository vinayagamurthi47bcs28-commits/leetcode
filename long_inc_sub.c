import java.util.Arrays;

class Solution {
    public int lengthOfLIS(int[] nums) {
        if (nums == null || nums.length == 0) return 0;
        
        // tails[i] stores the smallest tail of all increasing subsequences of length i + 1
        int[] tails = new int[nums.length];
        int size = 0; // Tracks the length of the longest increasing subsequence
        
        for (int x : nums) {
            int i = 0, j = size;
            
            // Binary search to find the correct insertion index for x in tails
            while (i < j) {
                int mid = i + (j - i) / 2;
                if (tails[mid] < x) {
                    i = mid + 1;
                } else {
                    j = mid;
                }
            }
            
            // Update the element at the found position
            tails[i] = x;
            
            // If x is larger than all elements in tails, it extends the active length
            if (i == size) {
                size++;
            }
        }
        
        return size;
    }
}

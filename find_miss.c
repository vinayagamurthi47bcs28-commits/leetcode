import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

class Solution {
    public List<Integer> findMissingElements(int[] nums) {
        List<Integer> result = new ArrayList<>();
        Set<Integer> set = new HashSet<>();
        
        int min = Integer.MAX_VALUE;
        int max = Integer.MIN_VALUE;
        
        // Populate the set and identify the bounds
        for (int num : nums) {
            set.add(num);
            if (num < min) min = num;
            if (num > max) max = num;
        }
        
        // Scan through the boundaries to identify omitted entries
        for (int i = min + 1; i < max; i++) {
            if (!set.contains(i)) {
                result.add(i);
            }
        }
        
        return result;
    }
}

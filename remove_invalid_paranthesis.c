import java.util.*;

class Solution {
    public List<String> removeInvalidParentheses(String s) {
        List<String> result = new ArrayList<>();
        if (s == null) return result;

        Queue<String> queue = new LinkedList<>();
        Set<String> visited = new HashSet<>();

        queue.add(s);
        visited.add(s);

        boolean foundValidAtThisLevel = false;

        while (!queue.isEmpty()) {
            int size = queue.size();
            
            // Process the current level entirely
            for (int i = 0; i < size; i++) {
                String current = queue.poll();

                if (isValid(current)) {
                    result.add(current);
                    foundValidAtThisLevel = true;
                }

                // If a valid string was found at this level, do not generate deeper states
                if (foundValidAtThisLevel) continue;

                // Generate next states by removing one parenthesis at a time
                for (int j = 0; j < current.length(); j++) {
                    char ch = current.charAt(j);
                    if (ch != '(' && ch != ')') continue; // Skip non-parentheses characters

                    // Create a candidate string by skipping character at index j
                    String candidate = current.substring(0, j) + current.substring(j + 1);

                    if (!visited.contains(candidate)) {
                        visited.add(candidate);
                        queue.add(candidate);
                    }
                }
            }

            // Once the level finishes, if we found any valid configuration, we stop BFS
            if (foundValidAtThisLevel) {
                break;
            }
        }

        return result;
    }

    // Helper method to check if a string contains balanced parentheses
    private boolean isValid(String s) {
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == '(') {
                count++;
            } else if (c == ')') {
                count--;
                if (count < 0) return false; // More closing than opening at any point
            }
        }
        return count == 0;
    }
}

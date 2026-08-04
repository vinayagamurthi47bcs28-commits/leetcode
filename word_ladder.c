import java.util.*;

class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        Set<String> wordSet = new HashSet<>(wordList);
        if (!wordSet.contains(endWord)) return 0;

        Queue<String> queue = new LinkedList<>();
        queue.add(beginWord);
        
        int level = 1;

        while (!queue.isEmpty()) {
            int size = queue.size();
            
            // Process all nodes at the current distance level
            for (int i = 0; i < size; i++) {
                String currentWord = queue.poll();
                if (currentWord.equals(endWord)) return level;

                char[] wordChars = currentWord.toCharArray();
                // Try changing every character position to 'a'-'z'
                for (int j = 0; j < wordChars.length; j++) {
                    char originalChar = wordChars[j];
                    
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == originalChar) continue;
                        wordChars[j] = c;
                        String nextWord = String.valueOf(wordChars);

                        if (wordSet.contains(nextWord)) {
                            queue.add(nextWord);
                            wordSet.remove(nextWord); // Act as visited
                        }
                    }
                    wordChars[j] = originalChar; // Revert back
                }
            }
            level++;
        }
        return 0;
    }
}

#include <stdio.h>
#include <string.h>

#define MAX_LEN 1005

void solve() {
    char s[MAX_LEN];
    scanf("%s", s);
    
    int sum = 0;
    int len = strlen(s);
    
    // Iterate through each character of the string
    for (int i = 0; i < len; i++) {
        // Check if the character is a digit
        if (s[i] >= '0' && s[i] <= '9') {
            sum += (s[i] - '0'); // Convert char to int and add to sum
        }
    }
    
    printf("%d\n", sum);
}

int main() {
    int t;
    if (scanf("%d", &t) == 1) {
        while (t--) {
            solve();
        }
    }
    return 0;
}

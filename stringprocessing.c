#include <stdio.h>
#include <string.h>
#define MAX_LEN 1005
void solve() {
    char s[MAX_LEN];
    scanf("%s", s);  
    int sum = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            sum += (s[i] - '0');
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

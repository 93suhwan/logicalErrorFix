#include <bits/stdc++.h>
using namespace std;
int t, n, c[2];
char s[100000];
signed main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%s", s);
    n = strlen(s);
    c[0] = c[1] = 0;
    for (int i = 0; i < n; i++) {
      s[i] == 'B' ? c[0]++ : c[1]++;
    }
    printf("%s\n", c[0] == c[1] ? "YES" : "NO");
  }
}

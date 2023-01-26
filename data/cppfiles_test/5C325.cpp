#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int T, n, ans, vis[N];
char s[N], t[N];
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) vis[i] = 0;
    cin >> (s + 1);
    cin >> (t + 1);
    ans = 0;
    for (int i = 1; i <= n; i++) {
      if (t[i] == '0') continue;
      if (s[i] == '0') {
        ans++;
      } else {
        if (s[i - 1] == '1' && !vis[i - 1]) {
          ans++;
          vis[i - 1] = 1;
        } else if (s[i + 1] == '1') {
          vis[i + 1] = 1;
          ans++;
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}

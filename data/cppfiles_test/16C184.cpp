#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
const int N = 1e6 + 5;
const int M = 2e3 + 5;
int T, n, m, x, y;
int a[N], ans[N], b[N];
char s[N], t[N];
signed main() {
  scanf("%d", &T);
  while (T--) {
    cin >> n;
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    for (int i = 1; i <= n; i++) t[i] = s[i];
    sort(s + 1, s + strlen(s + 1) + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      ans += (s[i] != t[i]);
    }
    printf("%d\n", ans);
  }
}

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int t, n, na, nb;
char a[maxn], b[maxn];
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while (t--) {
    nb = 0;
    na = 0;
    cin >> n;
    cin >> a + 1;
    cin >> b + 1;
    for (int i = 1; i <= n; i++) {
      if (a[i] == '1') na++;
    }
    for (int i = 1; i <= n; i++) {
      if (b[i] == '1') nb++;
    }
    int ans = -1, cnt = 0;
    if ((na == nb)) {
      for (int i = 1; i <= n; i++) {
        if (a[i] != b[i]) {
          cnt++;
        }
      }
      ans = cnt;
    }
    nb = 0;
    for (int i = 1; i <= n; i++) {
      b[i] = (b[i] == '1' ? '0' : '1');
      if (b[i] == '1') nb++;
    }
    cnt = 0;
    if (na == nb + 1) {
      for (int i = 1; i <= n; i++) {
        if (a[i] != b[i]) cnt++;
      }
      if (ans != -1)
        ans = min(ans, cnt);
      else
        ans = cnt;
    }
    printf("%d\n", ans);
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
inline int read() {
  bool ok = 0;
  int res = 0;
  char c;
  while (((c = getchar()) < '0' || c > '9') && c != '-')
    ;
  if (c == '-')
    ok = 1;
  else
    res = c - 48;
  while ((c = getchar()) >= '0' && c <= '9')
    res = (res << 3) + (res << 1) + (c - 48);
  return ok ? ~res + 1 : res;
}
int t, n, m, k, x, y, len, d;
int a[1000100];
int vis[1000100];
bool is_one(int i) { return (binary_search(a + 1, a + 1 + len, i)); }
int main() {
  cin.tie(0), ios::sync_with_stdio(false);
  cin >> t;
  while (t--) {
    cin >> n >> d;
    len = 0;
    for (int i = 0; i < n; ++i) {
      cin >> x;
      if (x == 1) a[++len] = i;
    }
    for (int i = 0; i <= n; ++i) vis[i] = 0;
    int ok = 1;
    int ans = 0;
    for (int i = 1; i <= len; ++i) {
      if (vis[a[i]]) continue;
      x = a[i];
      vis[x] = 1;
      int cnt = 1;
      while (is_one((x + d + n) % n)) {
        ++cnt;
        x = (x + d + n) % n;
        vis[x] = 1;
        if (x == a[i]) {
          ok = 0;
          break;
        }
      }
      ans = max(ans, cnt);
      if (ok == 0) break;
    }
    if (ok)
      cout << ans << endl;
    else
      cout << -1 << endl;
  }
  return 0;
}

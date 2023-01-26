#include <bits/stdc++.h>
using namespace std;
int n, a[1000005], d, b[2000005], ans;
bool vis[1000005];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> d, ans = 0;
    for (int i = 0; i < n; ++i) cin >> a[i], vis[i] = 0;
    for (int i = 0; i < n; ++i)
      if (!vis[i]) {
        int p = (i + d) % n, cnt = 0, ok = a[i], cur = 0, num = 0;
        b[cnt++] = a[i], vis[i] = 1;
        while (p != i) {
          b[cnt++] = a[p], vis[p] = 1;
          if (!a[p]) ok = 0;
          p = (p + d) % n;
        }
        if (ok) {
          puts("-1");
          goto out;
        }
        for (int j = cnt; j < (cnt << 1); ++j) b[j] = b[j - cnt];
        for (int j = 0; j < (cnt << 1); ++j) {
          if (!b[j])
            cur = 0;
          else
            ++cur;
          num = max(num, cur);
        }
        ans = max(ans, num);
      }
    printf("%d\n", ans);
  out:;
  }
  return 0;
}

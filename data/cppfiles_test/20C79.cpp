#include <bits/stdc++.h>
using namespace std;
char buf[1 << 21], *p1 = buf, *p2 = buf;
inline int qread() {
  register char c =
      (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2)
           ? EOF
           : *p1++);
  register int x = 0, f = 1;
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2)
             ? EOF
             : *p1++);
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + c - 48;
    c = (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2)
             ? EOF
             : *p1++);
  }
  return x * f;
}
int n, m;
bool mp[405][405];
int cnt[405][405], mn[405];
inline void Read() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      char c;
      cin >> c;
      mp[i][j] = c - '0';
    }
  }
}
inline void Prefix() {
  for (int i = 1; i <= n + 1; i++) {
    for (int j = 1; j <= m + 1; j++)
      cnt[i][j] = cnt[i - 1][j] + cnt[i][j - 1] - cnt[i - 1][j - 1] + mp[i][j];
  }
}
inline void Solve() {
  int ans = 0x3f3f3f3f;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 4; j <= n; j++) {
      mn[m + 1] = 0x3f3f3f3f;
      for (int k = m; k >= 1; k--) {
        int cur = (j - i - 1) - (cnt[j - 1][k] - cnt[i][k] - cnt[j - 1][k - 1] +
                                 cnt[i][k - 1]);
        cur += cnt[j - 1][k - 1] - cnt[i][k - 1];
        cur += (k - 1) - cnt[j][k - 1] + cnt[j - 1][k - 1];
        cur += (k - 1) - cnt[i][k - 1] + cnt[i - 1][k - 1];
        mn[k] = min(mn[k + 1], cur);
      }
      for (int k = 1; k <= m - 3; k++) {
        ans = min(ans, mn[k + 3] + (j - i - 1) -
                           (cnt[j - 1][k] - cnt[i][k] - cnt[j - 1][k - 1] +
                            cnt[i][k - 1]) -
                           (cnt[j - 1][k] - cnt[i][k]) -
                           (k - (cnt[i][k] - cnt[i - 1][k])) -
                           (k - (cnt[j][k] - cnt[j - 1][k])));
      }
    }
  }
  cout << ans << endl;
}
int main() {
  std::ios::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    Read();
    Prefix();
    Solve();
  }
  return 0;
}

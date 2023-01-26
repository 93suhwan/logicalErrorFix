#include <bits/stdc++.h>
using namespace std;
const int max_n = 100000;
char s[max_n + 1], t[max_n + 1];
int c[4];
inline void chmin(int& a, int b) {
  if (a > b) a = b;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int cas, n, ans;
  cin >> cas;
  while (cas--) {
    cin >> n >> s >> t;
    c[0] = c[1] = c[2] = c[3] = 0;
    for (int i = 0; i < n; i++) c[(s[i] - '0' << 1) | (t[i] - '0')]++;
    ans = n + 1;
    if (c[1] == c[2]) chmin(ans, c[1] << 1);
    if (c[3] == c[0] + 1) chmin(ans, (c[0] << 1) | 1);
    if (ans != n + 1)
      cout << ans << "\n";
    else
      cout << "-1"
           << "\n";
  }
  return 0;
}

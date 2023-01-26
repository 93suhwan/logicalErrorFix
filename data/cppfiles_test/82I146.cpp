#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int N = 3e5 + 5;
int t, n, q, l, r, f[N];
vector<int> p[N << 1][2];
string s;
int solve(int res) {
  int sum = f[l - 1] + (res - 1) / 2;
  int pos = lower_bound(p[sum + n][0].begin(), p[sum + n][0].end(), l - 1) -
            p[sum + n][0].begin();
  if (pos != p[sum + n][0].size()) return p[sum + n][0][pos] + 1;
  sum = f[l - 1] + (res + 1) / 2;
  pos = lower_bound(p[sum + n][1].begin(), p[sum + n][1].end(), l - 1) -
        p[sum + n][1].begin();
  if (pos != p[sum + n][1].size()) return p[sum + n][1][pos] + 1;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> q;
    cin >> s;
    s = ' ' + s;
    f[0] = 0;
    for (int i = 0; i <= 2 * n; ++i)
      for (int j = 0; j <= 1; ++j) p[i][j].clear();
    if (s[1] == '+')
      p[n][0].push_back(0);
    else
      p[n][1].push_back(0);
    for (int i = 1; i <= n; ++i) {
      int x = (s[i] == '+' ? 1 : -1) * (i & 1 ? 1 : -1);
      f[i] = f[i - 1] + x;
      if (i < n) {
        int y = (s[i + 1] == '+' ? 1 : -1) * ((i + 1) & 1 ? 1 : -1);
        if (y > 0)
          p[f[i] + n][0].push_back(i);
        else
          p[f[i] + n][1].push_back(i);
      }
    }
    while (q--) {
      cin >> l >> r;
      int res = f[r] - f[l - 1];
      if (res == 0)
        cout << 0 << '\n';
      else {
        if (res & 1)
          cout << 1 << '\n';
        else
          cout << 2 << '\n';
        if (res % 2 == 0) {
          cout << l << ' ';
          l++;
        }
        res = f[r] - f[l - 1];
        int ans = solve(res);
        assert(f[ans - 1] - f[l - 1] == f[r] - f[ans]);
        cout << ans << '\n';
      }
    }
  }
}

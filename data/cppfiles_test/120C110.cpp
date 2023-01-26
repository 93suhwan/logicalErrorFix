#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int lim = 200001;
int pre[200010][32];
void solve() {
  int l, r;
  cin >> l >> r;
  int res = 0;
  for (int b = 0; b < (32); ++b) res = max(res, pre[r][b] - pre[l - 1][b]);
  res = r - (l - 1) - res;
  cout << res << "\n";
}
int main() {
  {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
  };
  ll t = 1;
  cin >> t;
  memset(pre, 0, sizeof pre);
  for (int b = 0; b < (32); ++b) pre[0][b] = 0;
  for (int i = 1; i < (lim); ++i) {
    for (int b = 0; b < (32); ++b) {
      if (i & (1 << b))
        pre[i][b] = pre[i - 1][b] + 1;
      else
        pre[i][b] = pre[i - 1][b];
    }
  }
  while (t--) {
    solve();
  }
  return 0;
}

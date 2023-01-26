#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long inf = 1e9 + 7;
const double pi = acos(-1);
const double eps = 1e-9;
int n, q;
string s;
int ps[300005];
int sum(int l, int r) {
  if (l > r) return 0;
  return l & 1 ? ps[r] - ps[l - 1] : -ps[r] + ps[l - 1];
}
void solve() {
  cin >> n >> q >> s;
  ps[0] = 0;
  for (int i = 1; i <= n; ++i) {
    int val = (s[i - 1] == '+') ? 1 : -1;
    if (i & 1)
      ps[i] = ps[i - 1] + val;
    else
      ps[i] = ps[i - 1] - val;
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    if (sum(l, r) == 0)
      cout << "0\n";
    else if ((r - l + 1) & 1)
      cout << "1\n";
    else
      cout << "2\n";
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int test = 1;
  cin >> test;
  for (int tc = 1; tc <= test; ++tc) solve();
  return 0;
}

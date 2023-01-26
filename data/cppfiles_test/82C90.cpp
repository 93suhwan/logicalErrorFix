#include <bits/stdc++.h>
using namespace std;
const int Maxx = 3 * 1e5 + 99;
long long mod = 1e9 + 7;
int n, q, l, r;
int sum[Maxx];
string s;
void solve() {
  cin >> n >> q >> s;
  sum[0] = 0;
  for (int i = 0; i < n; ++i)
    sum[i + 1] = sum[i] + (s[i] == '+' ? 1 : -1) * ((i & 1) == 0 ? 1 : -1);
  vector<int> p[4 * n + 9];
  for (int i = 0; i < n; ++i) p[sum[i] + sum[i + 1] + 2 * n].push_back(i);
  auto get = [&](int l, int r) {
    int x = sum[l] + sum[r] + 2 * n;
    auto it = lower_bound(p[x].begin(), p[x].end(), l);
    assert(it != p[x].end() && *it < r);
    return *it;
  };
  for (int i = 0; i < q; ++i) {
    cin >> l >> r;
    --l;
    if ((r - l) & 1) {
      cout << "1\n" << get(l, r) + 1 << "\n";
    } else if (sum[l] == sum[r])
      cout << "0\n";
    else
      cout << "2\n" << l + 1 << " " << get(l + 1, r) + 1 << "\n";
  }
}
int main() {
  int t;
  ios::sync_with_stdio(false);
  cin.tie(0);
  ;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

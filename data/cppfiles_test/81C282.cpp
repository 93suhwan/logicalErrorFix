#include <bits/stdc++.h>
using namespace std;
void init() {}
void solve() {
  int n, k;
  cin >> n >> k;
  string str;
  cin >> str;
  vector<int> a(n + 1);
  for (int i = 0; i < n; i++) a[i + 1] = (str[i] == '+') ? 1 : -1;
  vector<int> s(n + 1);
  for (int i = 1; i <= n; i++) {
    s[i] = s[i - 1] + ((i & 1) ? a[i] : -1 * a[i]);
  }
  while (k--) {
    int l, r;
    cin >> l >> r;
    int sum = s[r] - s[l - 1];
    if (sum == 0)
      cout << 0 << endl;
    else if ((r - l + 1) & 1)
      cout << 1 << endl;
    else
      cout << 2 << endl;
  }
}
signed main() {
  iostream::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  init();
  int _;
  cin >> _;
  while (_--) {
    solve();
  }
  return 0;
}

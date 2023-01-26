#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    string s;
    cin >> n >> m >> s;
    vector<int> sum(n + 1);
    for (int i = 1; i <= n; i++) {
      sum[i] = sum[i - 1] + (s[i - 1] == '+' ? 1 : -1) * (i % 2 == 1 ? 1 : -1);
    }
    while (m--) {
      int l, r;
      cin >> l >> r;
      if (sum[r] - sum[l - 1] == 0)
        cout << 0 << '\n';
      else if ((r - l + 1) % 2 == 1)
        cout << 1 << '\n';
      else
        cout << 2 << '\n';
    }
  }
  return 0;
}

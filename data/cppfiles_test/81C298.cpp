#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, Q;
    cin >> n >> Q;
    string s;
    cin >> s;
    vector<int> pre(n, 0);
    pre[0] = s[0] == '+' ? 1 : -1;
    for (int i = 1; i < n; ++i) {
      pre[i] = pre[i - 1] + (s[i] == '+' ? 1 : -1) * ((i % 2) ? -1 : 1);
    }
    while (Q--) {
      int l, r;
      cin >> l >> r;
      --l, --r;
      int sum = pre[r] - (l ? pre[l - 1] : 0);
      if (sum == 0) {
        cout << 0;
      } else if ((r - l + 1) % 2 == 1) {
        cout << 1;
      } else {
        cout << 2;
      }
      cout << '\n';
    }
  }
}

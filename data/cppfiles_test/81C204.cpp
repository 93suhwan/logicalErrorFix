#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  static int a[1000000 + 5], pre[1000000 + 5];
  int tt;
  cin >> tt;
  while (tt--) {
    int n, q;
    string s;
    cin >> n >> q >> s;
    for (int i = 1; i <= n; i++) a[i] = (s[i - 1] == '+' ? 1 : -1);
    pre[0] = 0;
    for (int i = 1; i <= n; i++)
      pre[i] = pre[i - 1] + (i % 2 == 1 ? a[i] : -a[i]);
    while (q--) {
      int l, r;
      cin >> l >> r;
      int sum = 0;
      if (l <= r)
        sum = (l % 2 == 1) ? pre[r] - pre[l - 1] : pre[l - 1] - pre[r];
      if (sum == 0) {
        cout << "0\n";
        continue;
      }
      if ((r - l + 1) % 2 == 0)
        cout << "2\n";
      else
        cout << "1\n";
    }
  }
}

#include <bits/stdc++.h>
using namespace std;
int n, q, d[300010];
char t[300010];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> q >> t;
    for (int i = 1; i <= n; i++) {
      if (i % 2)
        d[i] = d[i - 1] + (t[i - 1] == '+' ? 1 : -1);
      else
        d[i] = d[i - 1] + (t[i - 1] == '+' ? -1 : 1);
    }
    for (int i = 0; i < q; i++) {
      int l, r;
      cin >> l >> r;
      if (d[r] == d[l - 1])
        cout << 0 << "\n";
      else
        cout << 2 - (abs(d[r] - d[l - 1]) % 2) << "\n";
    }
  }
}

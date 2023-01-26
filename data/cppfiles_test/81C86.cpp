#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
int sum[N];
signed main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  ;
  int T;
  cin >> T;
  while (T--) {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    sum[0] = 1;
    for (int i = 0; i < n; i++) {
      sum[i + 1] = sum[i] + (s[i] == '+' ? 1 : -1) * (i % 2 == 0 ? 1 : -1);
    }
    while (q--) {
      int l, r;
      cin >> l >> r;
      l -= 1;
      if ((r - l) % 2 == 1) {
        cout << "1\n";
      } else if (sum[l] == sum[r]) {
        cout << "0\n";
      } else {
        cout << "2\n";
      }
    }
  }
  return 0;
}

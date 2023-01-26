#include <bits/stdc++.h>
const int maxn = 1e6 + 10;
using namespace std;
int res[maxn];
int a[maxn];
int main() {
  string s;
  int T;
  cin >> T;
  while (T--) {
    int n, q;
    cin >> n >> q;
    cin >> s;
    s = " " + s;
    for (int i = 1; i <= n; i++) {
      if (i % 2 == 0) {
        if (s[i] == '+') {
          a[i] = -1;
        } else {
          a[i] = 1;
        }
      } else {
        if (s[i] == '+') {
          a[i] = 1;
        } else {
          a[i] = -1;
        }
      }
      res[i] = res[i - 1] + a[i];
    }
    int l, r;
    while (q--) {
      cin >> l >> r;
      if (res[r] - res[l - 1] == 0) {
        cout << 0 << endl;
      } else if ((res[r] - res[l - 1]) & 1) {
        cout << 1 << endl;
      } else {
        cout << 2 << endl;
      }
    }
  }
  return 0;
}

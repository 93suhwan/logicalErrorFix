#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 7;
const int M = 1e5 + 7;
const int inf = 0x3f3f3f3f;
const double eps = 1e-6;
int t;
int n, q;
string str;
int l, r;
int a[N];
int main() {
  cin >> t;
  while (t--) {
    memset(a, 0, sizeof(a));
    cin >> n >> q >> str;
    for (int i = 0; i < n; i++) {
      if (str[i] == '+') {
        if (i & 1)
          a[i + 1] = a[i] + 1;
        else
          a[i + 1] = a[i] - 1;
      } else {
        if (i & 1)
          a[i + 1] = a[i] - 1;
        else
          a[i + 1] = a[i] + 1;
      }
    }
    while (q--) {
      cin >> l >> r;
      int temp = a[r] - a[l - 1];
      if (temp == 0)
        cout << 0 << '\n';
      else if (temp & 1)
        cout << 1 << '\n';
      else
        cout << 2 << '\n';
    }
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t n, m, x, t, k, l, tc, r, s;
  cin >> tc;
  while (tc--) {
    cin >> n;
    int64_t a[n + 10];
    s = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      s += a[i];
    }
    if (s % n == 0) {
      cout << "0\n";
    } else {
      cout << "1\n";
    }
  }
}

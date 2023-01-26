#include <bits/stdc++.h>
using namespace std;
const int N = 300004;
int n, test, Q, a[N], s[N], b[N];
int cal(int l, int r) {
  if (r < l) {
    return 0;
  }
  return s[r] - s[l - 1];
}
int main() {
  freopen("data.input", "r", stdin);
  cin >> test;
  while (test--) {
    cin >> n >> Q;
    int cur = 1;
    for (int i = 1; i <= n; i++) {
      char c;
      cin >> c;
      if (c == '+')
        a[i] = 1;
      else
        a[i] = -1;
      s[i] = s[i - 1] + cur * a[i];
      cur *= -1;
    }
    for (int i = 1; i <= n; i++) {
      b[i] = cal(1, i - 1) - cal(i + 1, n);
    }
    while (Q--) {
      int l, r;
      cin >> l >> r;
      if (cal(l, r) == 0) {
        cout << 0 << endl;
      } else {
        if ((r - l + 1) % 2 == 1)
          cout << 1 << endl;
        else
          cout << 2 << endl;
      }
    }
  }
}

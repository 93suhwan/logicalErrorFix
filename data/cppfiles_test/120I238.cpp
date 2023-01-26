#include <bits/stdc++.h>
using namespace std;
int t, a, b, _a, _b, i, x, y, ans, e[200001];
int main() {
  for (i = 1; i <= 200000; i++) {
    if (!(i & 1))
      e[i] = e[i - 1] + 1;
    else
      e[i] = e[i - 1];
  }
  cin >> t;
  while (t--) {
    cin >> a >> b;
    ans = INT_MAX;
    if (a == b) {
      cout << 0 << endl;
      continue;
    }
    _a = log2(a), _b = log2(b);
    if (_a == _b)
      ans = 0;
    else {
      for (i = _a; i <= _b; i++) {
        x = 1 << i;
        if (i < _b) {
          y = 1 << (i + 1);
          y--;
          ans = min(ans, abs(a - x) + abs(b - y));
        } else
          ans = min(ans, x - a);
      }
    }
    cout << min(ans, e[b] - e[a - 1]) << endl;
  }
}

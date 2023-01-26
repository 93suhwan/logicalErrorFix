#include <bits/stdc++.h>
using namespace std;
int t, a, b, _a, _b, i, x, y, ans, e[200001];
int main() {
  for (i = 1; i <= 200000; i++) {
    if (i % 2 == 0)
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
        y = 1 << (i + 1);
        y--;
        if (i == _a)
          ans = min(ans, abs(b - y));
        else if (i == _b)
          ans = min(ans, abs(x - a));
        else
          ans = min(ans, abs(a - x) + abs(b - y));
      }
    }
    cout << min(ans, e[b] - e[a - 1]) << endl;
  }
}

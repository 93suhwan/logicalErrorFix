#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m, x, y, q, i, j, k, sum = 0, ans, a, b, v, c, d;
  cin >> n;
  multiset<long long int> s;
  for (i = 0; i < n; i++) {
    cin >> c;
    s.insert(c);
    sum += c;
  }
  v = sum;
  cin >> m;
  for (i = 0; i < m; i++) {
    cin >> x >> y;
    sum = v;
    auto it = s.lower_bound(x);
    if (it != s.end() && (*it) == x) {
      ans = y - sum + x;
      if (ans < 0) {
        ans = 0;
      }
      cout << ans << endl;
    } else {
      a = INT_MAX;
      c = INT_MAX;
      if (it != s.end()) {
        a = 0;
        sum -= *it;
        b = y - sum;
        if (b < 0) {
          b = 0;
        }
        a += b;
      }
      if (it != s.begin()) {
        it--;
        c = x - (*it);
        sum -= *it;
        d = y - sum;
        if (d < 0) {
          d = 0;
        }
        c += d;
      }
      ans = min(c, a);
      cout << ans << endl;
    }
  }
  return 0;
}

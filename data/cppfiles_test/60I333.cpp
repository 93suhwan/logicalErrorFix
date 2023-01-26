#include <bits/stdc++.h>
using namespace std;
double n, s, a, b, c, d, j;
vector<double> v;
double m, x, y, z;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int nt;
  cin >> nt;
  while (nt--) {
    s = 0;
    v.clear();
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> c;
      s = s + c;
      v.push_back(c);
    }
    sort(v.begin(), v.end());
    m = double(s) / double(n);
    s = 0;
    for (int i = 0; v[i] <= m; i++) {
      x = 2 * m - v[i];
      if (double(x) != m) {
        auto it = lower_bound(v.begin(), v.end(), x);
        if (it != v.end()) {
          auto jt = upper_bound(v.begin(), v.end(), x);
          j = (jt - v.begin());
          a = jt - it;
          s += a;
        }
      } else {
        auto it = lower_bound(v.begin(), v.end(), x);
        auto jt = upper_bound(v.begin(), v.end(), x);
        a = jt - it;
        s += ((a * (a - 1)) / 2);
        break;
      }
    }
    cout << s << '\n';
  }
  return 0;
}

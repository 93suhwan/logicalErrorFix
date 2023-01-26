#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long int t, n, i, x, mx, mn, f, j, s, r, y, c, m, k, c1;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<long long int> v;
    f = 0;
    for (i = 0; i < n; i++) {
      cin >> x;
      v.push_back(x);
      if (x == 0) f = 1;
    }
    s = 2;
    r = pow(3, n);
    while (s < r) {
      x = s;
      s++;
      c = c1 = 0;
      set<long long int> S;
      for (i = 0; i < n; i++) {
        if (x % 3 == 1)
          c += v[i];
        else if (x % 3 == 2)
          c -= v[i];
        else
          S.insert(v[i]);
        x /= 3;
      }
      if (S.count(c)) {
        f = 1;
      }
    }
    if (f)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}

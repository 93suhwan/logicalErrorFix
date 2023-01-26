#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long int t, n, i, x, mx, mn, f, j, s, r, y, c, m, k;
  cin >> t;
  while (t--) {
    cin >> n;
    set<long long int> S;
    vector<long long int> v;
    for (i = 0; i < n; i++) {
      cin >> x;
      v.push_back(x);
      S.insert(x);
    }
    s = 2;
    r = pow(3, n);
    f = 0;
    while (s < r) {
      x = s;
      c = 1;
      while (c < x) c *= 3;
      s++;
      if (c == x) continue;
      c = 0;
      for (i = 0; i < n; i++) {
        if (x % 3 == 1)
          c += v[i];
        else if (x % 3 == 2)
          c -= v[i];
        x /= 3;
      }
      if (S.count(c)) f = 1;
    }
    if (f)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}

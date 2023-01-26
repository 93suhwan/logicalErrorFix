#include <bits/stdc++.h>
using namespace std;
int main() {
  long long z, t;
  cin >> t;
  for (z = 0; z < t; z++) {
    long long n, i, p = 0, m, r = 0, l = 1000000000000000, h = 0;
    cin >> n;
    vector<long long> u, v;
    u.clear();
    v.clear();
    long long a[n];
    for (i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] % 2 == 0) {
        p++;
        u.push_back(i);
      } else {
        v.push_back(i);
        r++;
      }
    }
    if (abs(p - r) >= 2)
      cout << -1 << endl;
    else {
      if (p == r) {
        h = 0;
        for (i = 0; i < u.size(); i++) {
          h = h + abs(u[i] - (2 * i));
        }
        for (i = 0; i < v.size(); i++) {
          h = h + abs(v[i] - (2 * i + 1));
        }
        l = min(l, h / 2);
        h = 0;
        for (i = 0; i < v.size(); i++) {
          h = h + abs(v[i] - (2 * i));
        }
        for (i = 0; i < u.size(); i++) {
          h = h + abs(u[i] - (2 * i + 1));
        }
        l = min(l, h / 2);
      } else if (p > r) {
        h = 0;
        for (i = 0; i < u.size(); i++) {
          h = h + abs(u[i] - (2 * i));
        }
        for (i = 0; i < v.size(); i++) {
          h = h + abs(v[i] - (2 * i + 1));
        }
        l = min(l, h / 2);
      } else {
        h = 0;
        for (i = 0; i < v.size(); i++) {
          h = h + abs(v[i] - (2 * i));
        }
        for (i = 0; i < u.size(); i++) {
          h = h + abs(u[i] - (2 * i + 1));
        }
        l = min(l, h / 2);
      }
      cout << l << endl;
    }
  }
  return 0;
}

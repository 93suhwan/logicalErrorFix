#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
using namespace std;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  for (long long k = 0; k < t; k++) {
    long long n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    long long ax = 1, ay = 1;
    long long x = 0, y = 0;
    long long maxx = 0, minx = 0, maxy = 0, miny = 0;
    for (long long i = 0; i < s.size(); i++) {
      if (s[i] == 'U') {
        y++;
      } else {
        if (s[i] == 'D')
          y--;
        else {
          if (s[i] == 'R')
            x++;
          else
            x--;
        }
      }
      minx = min(minx, x);
      miny = min(miny, y);
      maxy = max(maxy, y);
      maxx = max(maxx, x);
      if (maxx + abs(minx) + 1 > m || maxy + abs(miny) + 1 > n) break;
      ax = minx * -1 + 1;
      ay = miny * -1 + 1;
    }
    cout << n - ay + 1 << " " << ax << '\n';
  }
}

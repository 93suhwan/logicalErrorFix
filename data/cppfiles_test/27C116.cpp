#include <bits/stdc++.h>
using namespace std;
const long long inf = 1100000000000000000;
void solve() {
  string s, t;
  cin >> s >> t;
  long long n = (long long)((s).size()), m = (long long)((t).size());
  long long pt0 = -1, pt1 = -1, pt = 0;
  for (long long i = 0; i < n; i++) {
    if (s[i] == t[0]) {
      if (i % 2 == 0 and pt0 == -1) pt0 = i;
      if (i % 2 == 1 and pt1 == -1) pt1 = i;
    }
  }
  long long ck = 0;
  if (pt0 != -1) {
    pt = 1;
    long long prev = pt0;
    for (long long i = pt0 + 1; i < n and pt < m; i++) {
      if (s[i] == t[pt] and (i - prev) % 2 == 1) {
        if (pt == m - 1) {
          if ((n - i) % 2 == 1) {
            pt++;
            prev = i;
          }
        } else {
          pt++;
          prev = i;
        }
      }
    }
    if (m == 1) {
      if ((n - pt0) % 2 == 1) ck = (pt == m);
    } else
      ck = (pt == m);
  }
  if (!ck and pt1 != -1) {
    pt = 1;
    long long prev = pt1;
    for (long long i = pt1 + 1; i < n and pt < m; i++) {
      if (s[i] == t[pt] and (i - prev) % 2 == 1) {
        if (pt == m - 1) {
          if ((n - i) % 2 == 1) {
            pt++;
            prev = i;
          }
        } else {
          pt++;
          prev = i;
        }
      }
    }
    if (m == 1) {
      if ((n - pt1) % 2 == 1) ck = (pt == m);
    } else
      ck = (pt == m);
  }
  if (ck)
    cout << "YES";
  else
    cout << "NO";
}
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  long long T = 1;
  cin >> T;
  while (T--) {
    solve();
    cout << '\n';
  }
  return 0;
}

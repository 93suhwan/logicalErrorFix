#include <bits/stdc++.h>
using namespace std;
const long long mo = 1e9 + 7;
long long nxt() {
  long long x;
  cin >> x;
  return x;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long qu = nxt();
  while (qu--) {
    string s, t;
    cin >> s >> t;
    for (long long i = 0; i < s.size(); i++) {
      long long idx = 0;
      queue<pair<pair<long long, long long>, long long> > q;
      q.push({{i, idx}, 0});
      bool ok = 0;
      while (q.size()) {
        pair<pair<long long, long long>, long long> u = q.front();
        q.pop();
        if (u.second == 0) {
          if (s[u.first.first] == t[u.first.second]) {
            if (u.first.second + 1 == t.size()) {
              ok = 1;
              break;
            }
            if (u.first.first + 1 < s.size())
              q.push({{u.first.first + 1, u.first.second + 1}, 0});
            if (u.first.first - 1 >= 0)
              q.push({{u.first.first - 1, u.first.second + 1}, 1});
          }
        } else {
          if (s[u.first.first] == t[u.first.second]) {
            if (u.first.second + 1 == t.size()) {
              ok = 1;
              break;
            }
            if (u.first.first - 1 >= 0)
              q.push({{u.first.first - 1, u.first.second + 1}, 1});
          }
        }
      }
      if (ok) {
        cout << "YES"
             << "\n";
        goto a;
      }
    }
    cout << "NO"
         << "\n";
  a:;
  }
  return 0;
}

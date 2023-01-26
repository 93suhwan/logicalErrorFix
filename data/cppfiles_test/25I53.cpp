#include <bits/stdc++.h>
using namespace std;
const long long N = 4e5 + 5;
void solve() {
  string s, t;
  cin >> s >> t;
  long long x = find(s.begin(), s.end(), t[0]) - s.begin();
  long long k = 0;
  bool f = true;
  string ans = "";
  string j;
  long long l = t.size() - 1;
  if (find(s.begin(), s.end(), t[0]) == s.end()) {
    cout << "NO"
         << "\n";
    return;
  }
  if (k == l) {
    cout << "YES"
         << "\n";
    return;
  }
  k = 1;
  while (1) {
    if (f) {
      auto it = find(s.begin() + x + 1, s.end(), t[k]);
      if (it - s.begin() < s.size()) {
        k++;
        x = it - s.begin();
        if (k > l) {
          cout << "YES"
               << "\n";
          return;
        }
        continue;
      } else {
        j = s.substr(0, x);
        reverse(j.begin(), j.end());
        auto it1 = find(j.begin(), j.end(), t[k]);
        if (it1 == j.end()) {
          cout << "NO"
               << "\n";
          return;
        } else {
          x = it1 - j.begin();
          f = false;
          k++;
          if (k > l) {
            cout << "YES"
                 << "\n";
            return;
          }
        }
      }
    } else {
      j = j.substr(x + 1);
      auto it1 = find(j.begin(), j.end(), t[k]);
      if (it1 == j.end()) {
        cout << "NO"
             << "\n";
        return;
      } else {
        x = it1 - j.begin();
        k++;
        if (k > l) {
          cout << "YES"
               << "\n";
          return;
        }
      }
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
void solve() {
  long long x1, p1;
  cin >> x1 >> p1;
  long long x2, p2;
  cin >> x2 >> p2;
  if (x1 == x2 && p1 == p2) {
    cout << "="
         << "\n";
    return;
  } else {
    string s1 = to_string(x1);
    string s2 = to_string(x2);
    long long temp1 = min(s1.length(), s2.length());
    long long temp2 = max(s1.length(), s2.length());
    if (s1.length() + p1 > s2.length() + p2) {
      cout << ">"
           << "\n";
      return;
    } else if (s1.length() + p1 < s2.length() + p2) {
      cout << "<"
           << "\n";
      return;
    } else {
      for (long long i = 0; i < temp1; i++) {
        if ((s1[i] - '0') > (s2[i] - '0')) {
          cout << ">"
               << "\n";
          return;
        }
        if ((s1[i] - '0') < (s2[i] - '0')) {
          cout << "<"
               << "\n";
          return;
        }
      }
      for (long long i = temp1; i < temp2; i++) {
        if (s1.length() > s2.length()) {
          if ((s1[i] - '0') > 0) {
            cout << ">"
                 << "\n";
            return;
          }
        } else {
          if ((s2[i] - '0') > 0) {
            cout << "<"
                 << "\n";
            return;
          }
        }
      }
    }
  }
  cout << "="
       << "\n";
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

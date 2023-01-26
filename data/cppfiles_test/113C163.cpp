#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target( \
    "fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimization("unroll-loops")
const long long remi = 998244353;
using namespace std;
void Sun_god() {
  string s1;
  long long x1;
  cin >> s1 >> x1;
  string s2;
  long long x2;
  cin >> s2 >> x2;
  if (s1.length() + x1 > s2.length() + x2) {
    cout << ">"
         << "\n";
  } else if (s1.length() + x1 < s2.length() + x2) {
    cout << "<"
         << "\n";
  } else {
    bool flag = 0;
    bool flag2 = 0;
    bool flag3 = 0;
    if (s1.length() > s2.length()) {
      flag2 = 1;
      for (long long i = s2.length(); i < s1.length(); i++) {
        if (s1[i] != '0') {
          flag = 1;
          break;
        }
      }
      s1.erase(s2.length());
    } else if (s1.length() < s2.length()) {
      flag3 = 1;
      for (long long i = s1.length(); i < s2.length(); i++) {
        if (s2[i] != '0') {
          flag = 1;
          break;
        }
      }
      s2.erase(s1.length());
    }
    if (s1 > s2) {
      cout << ">"
           << "\n";
    } else if (s2 > s1) {
      cout << "<"
           << "\n";
    } else {
      if (flag2 == 1 && flag == 1) {
        cout << ">"
             << "\n";
        return;
      }
      if (flag3 == 1 && flag == 1) {
        cout << "<"
             << "\n";
        return;
      }
      cout << "="
           << "\n";
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    Sun_god();
  }
  return 0;
}

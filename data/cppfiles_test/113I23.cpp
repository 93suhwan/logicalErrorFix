#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
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
    if (s1.length() > s2.length()) {
      s1.erase(s2.length());
    } else if (s1.length() < s2.length()) {
      s2.erase(s1.length());
    }
    if (s1 > s2) {
      cout << ">"
           << "\n";
    } else if (s2 > s1) {
      cout << "<"
           << "\n";
    } else {
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

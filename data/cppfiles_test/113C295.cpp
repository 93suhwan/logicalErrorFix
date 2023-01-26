#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
const long long remi = 998244353;
using namespace std;
void Sun_god() {
  long long x1, x2, p1, p2;
  cin >> x1 >> p1 >> x2 >> p2;
  string s1 = to_string(x1);
  string s2 = to_string(x2);
  if ((s1.length() + p1) > (s2.length() + p2)) {
    cout << ">\n";
  } else if ((s1.length() + p1) < (s2.length() + p2)) {
    cout << "<\n";
  } else {
    long long n1 = s1.length();
    long long n2 = s2.length();
    long long d = abs(n1 - n2);
    if (s1 > s2) {
      for (long long i = 0; i < d; i++) {
        s2.push_back('0');
      }
      if (s1 == s2) {
        cout << "=\n";
      } else {
        cout << ">\n";
      }
    } else if (s1 < s2) {
      for (long long i = 0; i < d; i++) {
        s1.push_back('0');
      }
      if (s1 == s2) {
        cout << "=\n";
      } else {
        cout << "<\n";
      }
    } else
      cout << "=\n";
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

#include <bits/stdc++.h>
using namespace std;
string f(long long x) {
  string s = "";
  while (x) {
    s += ('0' + x % 10);
    x /= 10;
  }
  reverse(s.begin(), s.end());
  return s;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cerr.tie(nullptr);
  long long t;
  cin >> t;
  for (long long e = 0; e < t; ++e) {
    long long x, p1;
    cin >> x >> p1;
    string s = f(x);
    long long p2;
    cin >> x >> p2;
    string t = f(x);
    long long n = s.length(), m = t.length();
    if (p1 > p2) {
      for (long long i = 0; i < p1 - p2; ++i) {
        s += '0';
        ++n;
        if (n > m) break;
      }
    } else if (p2 > p1) {
      for (long long i = 0; i < p2 - p1; ++i) {
        t += '0';
        ++m;
        if (m > n) break;
      }
    }
    if (n < m) {
      cout << "<\n";
    } else if (n > m) {
      cout << ">\n";
    } else {
      if (s < t)
        cout << "<\n";
      else if (t < s) {
        cout << ">\n";
      } else {
        cout << "=\n";
      }
    }
  }
}

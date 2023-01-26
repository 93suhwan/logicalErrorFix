#include <bits/stdc++.h>
using namespace std;
long long powerM(long long x, long long y, long long M = 1000000007) {
  long long v = 1;
  x = x % M;
  while (y > 0) {
    if (y & 1) v = (v * x) % M;
    y = y >> 1;
    x = (x * x) % M;
  }
  return v;
}
long long power(long long x, long long y) {
  long long v = 1;
  while (y > 0) {
    if (y & 1) v = v * x;
    y = y >> 1;
    x = x * x;
  }
  return v;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, i, j, ans = 0, m, l;
    string s, t;
    cin >> s >> t;
    n = s.length();
    m = t.length();
    if (m > n) {
      cout << "NO";
    } else if (m == n) {
      if (s == t)
        cout << "YES";
      else
        cout << "NO";
    } else {
      i = n - 1;
      for (j = m - 1; j >= 0 && i >= 0; j--, i--) {
        if (t[j] != s[i]) {
          while (t[j] != s[i] && i >= 0) {
            i -= 2;
          }
        }
      }
      if (i == -3 || i == -2)
        cout << "NO";
      else if (j == -1) {
        cout << "YES";
      } else {
        cout << "NO";
      }
    }
    cout << "\n";
  }
  return 0;
}

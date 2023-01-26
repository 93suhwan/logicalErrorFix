#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    string s;
    cin >> s;
    long long res = INT_MAX;
    long long x = 0;
    while (true) {
      long long cnt = 0;
      long long p = 0;
      long long q = n - 1;
      while (p <= q) {
        if (s[p] == s[q]) {
          p++;
          q--;
          continue;
        }
        if (s[p] == char('a' + x)) {
          p++;
          cnt++;
        } else if (s[q] == char('a' + x)) {
          q--;
          cnt++;
        } else {
          cnt = INT_MAX;
          break;
        }
      }
      res = min(res, cnt);
      if (char('a' + x) == 'z') {
        break;
      }
      x++;
    }
    if (res == INT_MAX) {
      cout << "-1"
           << "\n";
    } else {
      cout << res << "\n";
    }
  }
}

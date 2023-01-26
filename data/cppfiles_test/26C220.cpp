#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("O3")
#pragma GCC target("avx2")
using namespace std;
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  long long T;
  cin >> T;
  for (int t = (0); t <= ((int)(T)-1); ++t) {
    string s, ta, tb;
    cin >> s;
    for (long long i = 0; i < 5; ++i) {
      ta.push_back(s[2 * i]);
      tb.push_back(s[2 * i + 1]);
    }
    long long res = 10;
    {
      long long a = 0, b = 0;
      for (long long i = 0; i < 5; ++i) {
        if (a > b + (5 - i)) {
          res = min(res, 2 * i);
        }
        if (ta[i] != '0') {
          ++a;
        }
        if (a > b + (5 - i)) {
          res = min(res, 2 * i + 1);
        }
        if (tb[i] == '1') {
          ++b;
        }
        if (a > b + (5 - i - 1)) {
          res = min(res, 2 * i + 2);
        }
      }
    }
    {
      long long a = 0, b = 0;
      for (long long i = 0; i < 5; ++i) {
        if (b > a + (5 - i)) {
          res = min(res, 2 * i);
        }
        if (ta[i] == '1') {
          ++a;
        }
        if (b > a + (5 - i - 1)) {
          res = min(res, 2 * i + 1);
        }
        if (tb[i] != '0') {
          ++b;
        }
        if (b > a + (5 - i - 1)) {
          res = min(res, 2 * i + 2);
        }
      }
    }
    cout << res << "\n";
  }
  return 0;
}

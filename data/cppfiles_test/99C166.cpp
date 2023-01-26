#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  cin.tie(NULL);
  long long tt;
  cin >> tt;
  while (tt--) {
    long long x;
    cin >> x;
    long long d;
    cin >> d;
    vector<long long> foo;
    long long cur = x;
    for (long long i = 0; i < 4; i++) {
      long long min = i + 1;
      if (cur & 1) {
        cur += min;
      } else {
        cur -= min;
      }
      foo.push_back(cur);
    }
    long long temp = d % 4;
    if (temp == 2 or temp == 0) {
      if (temp == 0) temp += 4;
      cout << foo[temp - 1] << '\n';
    } else {
      if (temp == 1) {
        d--;
        long long dem = d / 4.0;
        if (x & 1) {
          cout << foo[temp - 1] + dem * 4 << '\n';
        } else {
          cout << foo[temp - 1] - dem * 4 << '\n';
        }
      } else {
        d--;
        long long dem = d / 4.0;
        if (x & 1) {
          cout << foo[temp - 1] - dem * 4 << '\n';
        } else {
          cout << foo[temp - 1] + dem * 4 << '\n';
        }
      }
    }
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long tt = 1;
  cin >> tt;
  while (tt--) {
    long long n;
    cin >> n;
    vector<long long> v(n);
    for (long long i = 0; i < n; ++i) cin >> v[i];
    long long sum = accumulate(v.begin(), v.end(), 0);
    if (sum == n) {
      cout << n + 1 << ' ';
      for (long long i = 1; i <= n; ++i) cout << i << ' ';
    } else {
      long long used = 0;
      for (long long i = 0; i < n - 1; ++i) {
        if (v[i] == 1 || used) {
          cout << i + 1 << ' ';
        } else {
          if (v[i] == 0 && v[i + 1] == 0) {
            cout << i + 1 << ' ';
          } else {
            cout << i + 1 << ' ' << n + 1 << ' ';
            used = 1;
          }
        }
      }
      if (used == 0) {
        cout << n << ' ' << n + 1;
      } else {
        cout << n << ' ';
      }
    }
    cout << '\n';
  }
  return 0;
}

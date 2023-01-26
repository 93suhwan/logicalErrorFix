#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (a == 0) {
    return b;
  }
  return gcd(b % a, a);
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> v(n);
    for (long long i = 0; i < n; ++i) {
      cin >> v[i];
    }
    if (n % 2 == 0) {
      for (long long i = 0; i < n; i += 2) {
        long long nok = abs(v[i] * v[i + 1]) / gcd(abs(v[i]), abs(v[i + 1]));
        cout << nok / v[i] << ' ' << -nok / v[i + 1] << ' ';
      }
      cout << '\n';
    } else {
      long long i = 0;
      for (; i < n - 3; i += 2) {
        long long nok = abs(v[i] * v[i + 1]) / gcd(abs(v[i]), abs(v[i + 1]));
        cout << nok / v[i] << ' ' << -nok / v[i + 1] << ' ';
      }
      long long nok1 = abs(v[i] * v[i + 1]) / gcd(abs(v[i]), abs(v[i + 1]));
      long long nok = abs(nok1 * v[i + 2]) / gcd(nok1, abs(v[i + 2]));
      cout << nok / v[i] * 2 << ' ' << -nok / v[i + 1] << ' ' << -nok / v[i + 2]
           << '\n';
    }
  }
  return 0;
}

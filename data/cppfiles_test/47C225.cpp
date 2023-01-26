#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const long long mod = 1e9 + 7;
const double INF = 0x3f3f3f3f;
const long long N = 2e5 + 10, M = 100;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    vector<long long> a, b;
    long long n, k;
    cin >> n >> k;
    for (long long i = 1; i <= n; i++) {
      long long x;
      cin >> x;
      if (x < 0)
        a.push_back(-x);
      else
        b.push_back(x);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    long long na = a.size();
    long long nb = b.size();
    long long res = 0;
    if (na && nb) {
      if (a[na - 1] > b[nb - 1]) {
        res += a[na - 1];
        na = max(na - k, 0LL);
      } else {
        res += b[nb - 1];
        nb = max(nb - k, 0LL);
      }
    } else if (na > 0) {
      res += a[na - 1];
      na = max(na - k, 0LL);
    } else {
      res += b[nb - 1];
      nb = max(nb - k, 0LL);
    }
    while (na > 0) {
      res += a[na - 1] * 2;
      na = max(na - k, 0LL);
    }
    while (nb > 0) {
      res += b[nb - 1] * 2;
      nb = max(nb - k, 0LL);
    }
    cout << res << '\n';
  }
  return 0;
}

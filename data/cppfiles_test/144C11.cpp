#include <bits/stdc++.h>
const long long N = 1e6 + 10;
const long long INF = 1e18;
const long long inf = -1e18;
const long long MOD = 998244353;
using namespace std;
long long n, m, k;
long long inv(long long a, long long m) {
  long long temp = m, q, t, u = 0, v = 1;
  if (m == 1) return 0;
  while (a > 1) {
    q = a / m;
    t = m;
    m = a % m;
    a = t;
    t = u;
    u = v - q * u;
    v = t;
  }
  if (v < 0) v += temp;
  return v;
}
int main() {
  ios_base::sync_with_stdio(0);
  int o = 1;
  cin >> o;
  while (o--) {
    cin >> n >> m >> k;
    deque<long long> a;
    for (int i = 0; i < n; i++) {
      a.push_back(i + 1);
    }
    for (int i = 1; i <= k; i++) {
      long long cnt = 1;
      for (int j = 1; j <= m; j++) {
        if (j <= n % m) {
          cout << n / m + 1 << " ";
          for (int j = cnt; j <= cnt + n / m + 1 - 1; j++) {
            cout << a[j - 1] << " ";
          }
          cnt += n / m + 1;
        } else {
          cout << n / m << " ";
          for (int j = cnt; j <= cnt + n / m - 1; j++) {
            cout << a[j - 1] << " ";
          }
          cnt += n / m;
        }
        cout << "\n";
      }
      for (int j = 1; j <= (n % m) * (n / m + 1); j++) {
        long long qwe = a[0];
        a.pop_front();
        a.push_back(qwe);
      }
    }
  }
}

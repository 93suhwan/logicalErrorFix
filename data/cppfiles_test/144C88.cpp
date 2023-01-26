#include <bits/stdc++.h>
using namespace std;
const long long int ll_MAX = 1e14 + 5;
const long long int MOD = 998244353;
long long int fast_expo(long long int x, long long int p) {
  if (p == 0)
    return 1;
  else if (p % 2 == 0) {
    long long int t = fast_expo(x, p / 2) % MOD;
    return (t * t) % MOD;
  } else
    return (x * (fast_expo(x, p - 1)) % MOD) % MOD;
}
long long int gcd(long long int a, long long int b) {
  if (a == 0 || b == 0)
    return a + b;
  else
    return gcd(b % a, a);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long int t_c;
  t_c = 1;
  cin >> t_c;
  for (long long int t_i = 0; t_i < t_c; ++t_i) {
    long long int n, m, k;
    cin >> n >> m >> k;
    long long int curr = 1;
    long long int val1 = n / m, cnt1 = m - n % m;
    long long int val2 = n / m + 1, cnt2 = n % m;
    for (long long int i = 1; i <= k; ++i) {
      long long int tmp = curr;
      for (long long int j = 1; j <= m; ++j) {
        if (j <= cnt2) {
          cout << val2 << " ";
          for (long long int x = 1; x <= val2; ++x) {
            cout << tmp << " ";
            tmp = tmp % n + 1;
          }
          curr = tmp;
        } else {
          cout << val1 << " ";
          for (long long int x = 1; x <= val1; ++x) {
            cout << tmp << " ";
            tmp = tmp % n + 1;
          }
        }
        cout << "\n";
      }
    }
    cout << "\n";
  }
  return 0;
}

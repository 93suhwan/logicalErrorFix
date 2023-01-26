#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
const int maxm = 1e6 + 10;
const int mod = 1e9 + 7;
const double eps = 1e-9;
bool deb = 1;
long long qpow(long long x, long long y) {
  if (!y) return 1;
  long long res = 1;
  if (y % 2) res = x;
  return ((res * qpow((x * x) % mod, y / 2)) % mod);
}
void oper() {
  long long n, k;
  cin >> n >> k;
  long long ans;
  if (n % 2 == 1)
    ans = qpow(qpow(2, n - 1) + 1, k);
  else {
    ans = qpow((qpow(2, n - 1) - 1), k);
    long long dp = 1;
    for (long long i = 1; i <= k; i++) {
      ans += qpow(qpow(2, n - 1) - 1, n - i) * qpow(qpow(2, n), i - 1);
    }
  }
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) oper();
  return 0;
}

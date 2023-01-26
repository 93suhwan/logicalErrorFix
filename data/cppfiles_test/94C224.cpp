#include <bits/stdc++.h>
using namespace std;
long long min(long long a, long long b) { return a < b ? a : b; }
long long max(long long a, long long b) { return a > b ? a : b; }
bool isprime(long long k) {
  bool is = 1;
  for (long long i = 2; i * i <= k; i++)
    if (k % i == 0) is = 0;
  return k > 1 ? is : 0;
}
const double PI = acos(-1);
long long n, k;
long long a[15];
inline void sol() {
  cin >> n >> k;
  k++;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  if (n == 1) {
    cout << k << "\n";
    return;
  }
  long long tot = 0;
  for (long long i = 2; i <= n; i++) {
    long long pw = 1;
    for (long long j = a[i - 1]; j < a[i]; j++) pw *= 10;
    pw -= 1;
    if (tot + pw >= k) {
      long long res = 0;
      pw = 1;
      for (long long j = 0; j < a[i - 1]; j++) res = res * 10 + 9, pw *= 10;
      k -= tot;
      cout << k * pw + res << "\n";
      return;
    } else
      tot += pw;
  }
  long long res = 0, pw = 1;
  for (long long i = 0; i < a[n]; i++) res = res * 10 + 9, pw *= 10;
  cout << (k - tot) * pw + res << "\n";
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long _ = 1;
  cin >> _;
  while (_--) sol();
  return 0;
}

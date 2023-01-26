#include <bits/stdc++.h>
using namespace std;
const long double PI = 3.1415926535897923846;
const long long int MOD = 1000000007;
const long long int N = 998244353;
long long int power(long long int x, long long int n) {
  long long int res = 1;
  while (n > 0) {
    if (n & 1) res = res * x % MOD;
    x = x * x % MOD;
    n >>= 1;
  }
  return res;
}
long long int modinverse(long long int a) { return power(a, MOD - 2); }
void solve() {
  long long int n;
  cin >> n;
  vector<long long int> a(n);
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  double ans = 0;
  ans += a[n - 1];
  double sum = 0;
  for (long long int i = 0; i < n - 1; i++) sum += a[i];
  sum = (sum * 1.0) / (n - 1);
  ans = ans + sum;
  std::cout << setprecision(15) << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int test = 1;
  cin >> test;
  while (test--) {
    solve();
  }
  cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC
       << "ms\n";
}

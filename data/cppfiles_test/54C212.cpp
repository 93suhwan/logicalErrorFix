#include <bits/stdc++.h>
long long int power(long long int a, long long int b) {
  long long int res = 1;
  a %= 1000000007;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % 1000000007;
    a = a * a % 1000000007;
  }
  return res;
}
using namespace std;
const long double PI = acos(-1);
const long double EPS = 1e-9;
const long long int INF = 1e18;
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
void solve() {
  long long int n, k, i;
  cin >> n >> k;
  long long int ans00[k + 1];
  long long int ans01[k + 1];
  long long int ans10[k + 1];
  long long int ans11[k + 1];
  long long int ans[k + 1];
  long long int answ[k + 1];
  answ[0] = 1;
  ans[0] = 1;
  long long int fo = (power(2, n - 1) - 1) % 1000000007;
  long long int fe = (power(2, n - 1)) % 1000000007;
  for (i = 1; i <= k; i++) {
    answ[i] = (answ[i - 1] * (2 * fe)) % 1000000007;
    if (n % 2) {
      ans11[i] = ans[i - 1];
    } else
      ans11[i] = 0;
    if ((n % 2) == 0) {
      ans10[i] = answ[i - 1];
    } else
      ans10[i] = 0;
    if (n % 2) {
      ans00[i] = (((ans[i - 1]) * (fo + 1)) % 1000000007);
    } else {
      ans00[i] = (((ans[i - 1]) * (fe - 1)) % 1000000007);
    }
    ans[i] = ans00[i] + ans10[i] + ans11[i];
    ans[i] = (ans[i] % 1000000007);
  }
  cout << ans[k] << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int TC = 1, te = 0;
  cin >> TC;
  while (te++ < TC) {
    solve();
  }
  cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC
       << "ms\n";
  return 0;
}

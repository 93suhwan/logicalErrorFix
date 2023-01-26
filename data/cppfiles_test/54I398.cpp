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
  long long int n, k;
  cin >> n >> k;
  long long int fact = 0;
  if (n % 2) fact++;
  fact = fact + power(2, n - 1);
  fact %= 1000000007;
  long long int ans = (power(fact, k));
  cout << ans << endl;
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

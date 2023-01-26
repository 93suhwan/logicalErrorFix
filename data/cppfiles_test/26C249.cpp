#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const int32_t M = 1e9 + 7;
const int32_t MM = 998244353;
const int32_t N = 2e5 + 1;
long long f[N];
long long Power(long long a, long long b) {
  long long result = 1;
  a %= 1000000007;
  while (b) {
    if (b % 2 == 1) result *= a;
    a *= a;
    a %= 1000000007;
    result %= 1000000007;
    b /= 2;
  }
  return result;
}
long long Mod_Inv(long long a) {
  a %= 1000000007;
  a = Power(a, 1000000007 - 2);
  return a;
}
long long Factorial[500001];
long long Make_factorial() {
  Factorial[0] = 1;
  for (long long i = 1; i < 500001; ++i) {
    Factorial[i] = Factorial[i - 1] * i;
    Factorial[i] %= 1000000007;
  }
  return 0;
}
long long Implement_Factorial = Make_factorial();
long long ncr(long long n, long long r) {
  if (n < r) return 0;
  long long ans = Factorial[n] % 1000000007;
  ans *= Mod_Inv(Factorial[r]);
  ans %= 1000000007;
  ans *= Mod_Inv(Factorial[n - r]);
  ans %= 1000000007;
  return ans;
}
void solve(long long tc) {
  long long n;
  cin >> n;
  cout << (Factorial[2 * n] * Mod_Inv(2)) % M << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  for (long long i = 1; i <= t; i++) solve(i);
}

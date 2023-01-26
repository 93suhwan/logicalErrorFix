#include <bits/stdc++.h>
using namespace std;
const int Mod = 998244353;
const int N = 1e6 + 10;
long long poww(long long a, long long b, long long mod) {
  long long res = 1;
  if (b < 0) b = (b % (mod - 1) + mod - 1) % (mod - 1);
  for (; b; b >>= 1, a = 1ll * a * a % mod)
    if (b & 1) res = 1ll * res * a % mod;
  return res;
}
long long poww3(long long a, long long b) {
  long long res = 1;
  for (; b; b >>= 1, a = 1ll * a * a)
    if (b & 1) res = 1ll * res * a;
  return res;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(9);
  int T = 1;
  cin >> T;
  while (T--) {
    long long n;
    cin >> n;
    cout << -1 * (n - 1) << ' ' << n << '\n';
  }
  return 0;
}

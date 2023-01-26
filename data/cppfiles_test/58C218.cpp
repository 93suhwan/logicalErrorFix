#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e12;
const long long NINF = -INF;
const int mod = 1000000007;
const int inf = 1e7;
const int ninf = -mod;
const int nnf = -mod;
const int MOD = 998244353;
long long pow(long long a, long long b, long long mod) {
  if (b == 0) return 1;
  if (b == 1) return a;
  long long res = pow(a, b / 2, mod);
  if (b & 1) {
    return (res % mod * (res % mod * a % mod) % mod) % mod;
  } else {
    return (res % mod * res % mod) % mod;
  }
}
long long mul(long long a, long long b) {
  return ((a % MOD) * (b % MOD)) % MOD;
}
long long tri(long long a, long long b, long long c) {
  return mul(mul(a, b), c);
}
void solve() {
  int n;
  cin >> n;
  int i, j;
  string a[3];
  for (i = 1; i <= 2; i++) {
    cin >> a[i];
  }
  for (i = 0; i < n; i++) {
    if (a[1][i] == a[2][i] && a[1][i] == '1') {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}

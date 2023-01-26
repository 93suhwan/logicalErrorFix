#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
const long long mod = 1e9 + 7;
long long bigmod(long long a, long long b) {
  if (b == 0) return 1;
  long long ans = bigmod(a, b / 2);
  ans = (ans * ans) % mod;
  if (b & 1) ans *= a;
  return ans % mod;
}
void solve() {
  long long n;
  cin >> n;
  cout << (bigmod(4, pow(2, n) - 2) * 6) % mod << nl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
}

#include <bits/stdc++.h>
using namespace std;
const long long m = 1e9 + 7, N = 2e5 + 1, INF = 1e6;
long long binpow(long long a, long long b) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
void solve() {
  long long n, k, ans = 0;
  cin >> n >> k;
  while (k > 0) {
    long long p = log2(k);
    k -= (1 << p);
    ans = (ans + binpow(n, p)) % m;
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

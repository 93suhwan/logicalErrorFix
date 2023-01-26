#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("popcnt")
using namespace std;
const long long dx[4] = {1, -1, 0, 0};
const long long dy[4] = {0, 0, 1, -1};
const long long mod = 1e9 + 7;
const long long inf = 1e18;
const long long N = 3e5;
const long long col = 107;
void fre_open() {
  freopen("file.in", "r", stdin);
  freopen("file.out", "w", stdout);
}
long long binpow(long long n, long long k) {
  if (k == 0) return 1ll;
  if (k % 2) return binpow(n, k - 1) * n;
  long long kk = binpow(n, k / 2);
  return kk * kk;
}
void solve() {
  long long n;
  cin >> n;
  --n;
  cout << 3 << ' ' << n - 3 << ' ' << 1 << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long tt = 1;
  cin >> tt;
  while (tt--) solve();
}

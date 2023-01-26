#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 20;
const long long INFLL = 2e18 + 20;
const long double pi = 3.14159265358979323846;
const long double EPSILION = 0.000000000001;
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 20;
void usaco(string filename) {
  freopen((filename + ".in").c_str(), "r", stdin);
  freopen((filename + ".out").c_str(), "w", stdout);
}
void init() {}
long long getCount(long long n, long long k) {
  long long res = (n >> (k + 1)) << k;
  if ((n >> k) & 1) {
    res += n & ((1LL << k) - 1);
  }
  return res;
}
void solve() {
  long long l, r;
  cin >> l >> r;
  long long ans = r - l + 1;
  for (auto i = 0; i < 30; i++) {
    long long x = getCount(l, i);
    long long y = getCount(r + 1, i);
    ans = min(ans, (r - l + 1) - (y - x));
  }
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  init();
  long long t = 1;
  cin >> t;
  for (long long i = 1; i <= t; i++) {
    solve();
  }
}

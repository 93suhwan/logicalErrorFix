#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
const long long INF = 1e18;
const long long MOD = 1e9 + 7;
const long long mod = 998244353;
const long long mxN = 1e6 + 1;
void fileio() {}
void solve() {
  long long n, m, k;
  cin >> n >> m >> k;
  vector<long long> x(n);
  for (long long i = 0; i < n; i++) cin >> x[i];
  ;
  vector<long long> y(m);
  for (long long i = 0; i < m; i++) cin >> y[i];
  ;
  vector<pair<long long, long long> > vx(k), vy(k);
  for (long long i = 0; i < k; i++) cin >> vx[i].first >> vx[i].second;
  for (long long i = 0; i < k; i++) {
    vy[i].first = vx[i].second;
    vy[i].second = vx[i].first;
  }
  sort(vx.begin(), vx.end());
  ;
  sort(vy.begin(), vy.end());
  ;
  long long ans = 0;
  long long j = 0;
  for (long long i = 0; i < n - 1; i++) {
    long long x1 = x[i], x2 = x[i + 1];
    while (j < k && vx[j].first <= x1) j++;
    map<long long, long long> mp;
    long long c = 0;
    while (j < k && vx[j].first < x2) {
      mp[vx[j].second]++;
      j++;
      c++;
    }
    ans += c * (c - 1) / 2;
    for (auto it : mp) ans -= it.second * (it.second - 1) / 2;
  }
  j = 0;
  for (long long i = 0; i < m - 1; i++) {
    long long y1 = y[i], y2 = y[i + 1];
    while (j < k && vy[j].first <= y1) j++;
    map<long long, long long> mp;
    long long c = 0;
    while (j < k && vy[j].first < y2) {
      mp[vy[j].second]++;
      j++;
      c++;
    }
    ans += c * (c - 1) / 2;
    for (auto it : mp) ans -= it.second * (it.second - 1) / 2;
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  fileio();
  int tc;
  cin >> tc;
  while (tc--) solve();
}

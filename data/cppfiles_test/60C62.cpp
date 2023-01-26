#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC target("avx2")
using namespace std;
using pii = pair<long long, long long>;
using vvi = vector<vector<long long> >;
const long long N = 1e6 + 5;
const long long INF = 1e18 + 7;
const long long MOD = 1e9 + 7;
const double eps = 1e-6;
const long long B = 800;
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (long long &i : a) cin >> i;
  long long ans = a[0];
  for (long long i = 1; i < n; i++) ans &= a[i];
  cout << ans;
  cout << '\n';
}
long long test = 1;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> test;
  while (test--) solve();
  return 0;
}

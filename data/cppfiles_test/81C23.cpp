#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
using ll = long long;
using ld = long double;
const ll MOD = 1000000007;
const ll root = 3;
ll binpow(ll a, ll b) {
  ll res = 1;
  while (b) {
    if (b & 1) res = (res * a) % MOD;
    a = (a * a) % MOD;
    b >>= 1;
  }
  return res;
}
ll modInv(ll a) { return binpow(a, MOD - 2); }
const int INF = 0x3f3f3f3f;
const int NINF = 0xc0c0c0c0;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll NINFLL = 0xc0c0c0c0c0c0c0c0;
const int mxN = 500001;
pair<int, int> arr[mxN];
int n, d;
void solve() {
  cin >> n >> d;
  for (int i = (0); i < (n); ++i) {
    cin >> arr[i].first >> arr[i].second;
  }
  sort(arr, arr + n, [&](pair<int, int> a, pair<int, int> b) {
    if (max(a.first, a.second) == max(b.first, b.second)) {
      return a.first < b.first;
    }
    return max(a.first, a.second) < max(b.first, b.second);
  });
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i].first >= d) {
      cnt++;
      d = max(d, arr[i].second);
    }
  }
  cout << cnt << "\n";
}
int main() {
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  cin.tie(0)->sync_with_stdio(0);
  int T = 1;
  for (int tc = 1; tc <= T; tc++) {
    solve();
  }
  return 0;
}

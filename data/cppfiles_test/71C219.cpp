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
vector<long long> v;
bool bit(long long mask, long long i) { return (mask >> i & 1); }
void gen() {
  for (long long x = 0; x < 10; x++) {
    for (long long y = 0; y < 10; y++) {
      if (x == y && x == 0) continue;
      for (long long len = 1; len <= 12; len++) {
        for (long long mask = 0; mask <= (1 << len) - 1; mask++) {
          long long num = 0;
          for (long long i = 0; i < len; i++) {
            num *= 10;
            if (bit(mask, i))
              num += x;
            else
              num += y;
          }
          v.push_back(num);
        }
      }
    }
  }
  sort(v.begin(), v.end());
}
void solve() {
  long long n, k;
  cin >> n >> k;
  long long ans = INF;
  if (k == 1) {
    string s = to_string(n);
    long long len = (long long)(s).size();
    for (long long i = 0; i < 10; i++) {
      long long x = len, num = 0;
      while (x--) num = num * 10 + i;
      if (num >= n) ans = min(ans, num);
    }
    cout << ans << '\n';
    return;
  }
  if (k == 2) {
    long long l = 0, r = (long long)(v).size() - 1;
    while (l <= r) {
      long long mid = l + r >> 1;
      if (v[mid] >= n) {
        ans = v[mid];
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    cout << ans << '\n';
    return;
  }
  cout << '\n';
}
long long test = 1;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  gen();
  cin >> test;
  while (test--) solve();
  return 0;
}

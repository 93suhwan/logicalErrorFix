#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
long long MOD = 998244353;
double eps = 1e-12;
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<long long> v = {0};
  for (long long i = 0; i < n; i++) {
    long long val;
    cin >> val;
    v.push_back(val);
  }
  long long ans = -0x3f3f3f3f3f3f3f3f;
  for (int i = max(1ll, n - 500); i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      long long val = 1ll * i * j - 1ll * k * (v[i] | v[j]);
      ans = max(ans, val);
    }
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  for (int it = 1; it <= t; it++) {
    solve();
  }
  return 0;
}

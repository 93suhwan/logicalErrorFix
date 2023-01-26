#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("avx2")
using namespace std;
long long mult_mod(long long x, long long y, long long mod) {
  return (x * y - (long long)(x / (long double)mod * y + 1e-3) * mod + mod) %
         mod;
}
long long pow_mod(long long a, long long b, long long p) {
  long long res = 1;
  while (b) {
    if (b & 1) res = mult_mod(res, a, p);
    a = mult_mod(a, a, p);
    b >>= 1;
  }
  return res % p;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
const int N = 2e5 + 10;
int t, n, k;
int a[N], ans[N];
vector<int> vec, v[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> t;
  while (t--) {
    vec.clear();
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      ans[i] = 0;
      v[i].clear();
    }
    for (int i = 1; i <= n; i++) v[a[i]].push_back(i);
    for (int i = 1; i <= n; i++) {
      if (v[i].size() >= k)
        for (int j = 0; j < k; j++) ans[v[i][j]] = j + 1;
      else
        for (auto x : v[i]) vec.push_back(x);
    }
    for (int i = 0; i + k - 1 < vec.size(); i += k)
      for (int j = i; j <= i + k - 1; j++) ans[vec[j]] = j - i + 1;
    for (int i = 1; i <= n; i++) cout << ans[i] << (i == n ? "\n" : " ");
  }
  return 0;
}

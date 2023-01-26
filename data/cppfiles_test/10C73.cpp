#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long bigmod(long long a, long long b) {
  long long ans = 1;
  while (b > 0) {
    if (b & 1) {
      ans = (ans * 1ll * a) % mod;
    }
    a = (a * 1ll * a) % mod;
    b >>= 1;
  }
  return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n, m, k, r, c;
  cin >> n >> m >> k >> r >> c;
  pair<long long, long long> a, b;
  cin >> a.first >> a.second >> b.first >> b.second;
  long long up = n * m;
  if (!(a.first == b.first && a.second == b.second)) {
    up -= r * c;
  };
  cout << bigmod(k, up) << "\n";
  return 0;
}

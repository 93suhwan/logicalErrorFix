#include <bits/stdc++.h>
const long double pi = 3.1415926535898;
const long long mod = 1e9 + 7;
using namespace std;
vector<vector<long long>> v(105);
long long h[105], cnt[105];
long long f[105], mf[105];
long long modpower(long long a, long long b) {
  if (b == 0) return 1;
  long long c = modpower(a, b / 2) % mod;
  if (b % 2)
    return (((a * c) % mod) * c) % mod;
  else
    return (c * c) % mod;
}
void dfs(long long x, long long p) {
  cnt[h[x]]++;
  for (auto i : v[x]) {
    if (i != p) {
      h[i] = h[x] + 1;
      dfs(i, x);
    }
  }
}
long long ncr(long long n, long long r) {
  if (n < r) {
    return 0;
  }
  return (((f[n] * mf[n - r]) % mod) * mf[r]) % mod;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  f[0] = mf[0] = 1;
  for (long long i = 1; i <= 100; i++) {
    f[i] = (f[i - 1] * i) % mod;
    mf[i] = modpower(f[i], mod - 2);
  }
  long long t;
  cin >> t;
  while (t--) {
    long long n, k, x, y;
    cin >> n >> k;
    for (long long i = 1; i <= n; i++) {
      v[i].clear();
    }
    for (long long i = 0; i < n - 1; i++) {
      cin >> x >> y;
      v[x].push_back(y);
      v[y].push_back(x);
    }
    if (k == 2) {
      cout << (n * (n - 1)) / 2 << "\n";
      continue;
    }
    long long ans = 0;
    for (long long i = 1; i <= n; i++) {
      memset(h, 0, sizeof(h));
      memset(cnt, 0, sizeof(cnt));
      dfs(i, 0);
      for (long long j = 1; j <= n; j++) {
        ans += ncr(cnt[j], k);
        ans %= mod;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 200005;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;
const long double EPS = 1e-9;
inline long long summ(long long x, long long y) {
  return (x + y) - (x + y >= MOD) * MOD;
}
inline long long difm(long long x, long long y) {
  return (x - y) + (x - y < 0) * MOD;
}
inline long long mulm(long long x, long long y) { return x * y % MOD; }
long long bin_pow(long long a, long long n) {
  long long res = 1;
  while (n) {
    if (n % 2) {
      n--;
      res = mulm(res, a);
    } else {
      n /= 2;
      a = mulm(a, a);
    }
  }
  return res;
}
inline long long rev(long long n) { return bin_pow(n, MOD - 2); }
inline long long divm(long long x, long long y) { return mulm(x, rev(y)); }
long long fact[MAXN], fact_rev[MAXN];
void fact_init() {
  fact[0] = fact_rev[0] = 1;
  for (long long i = 1; i < MAXN; i++) {
    fact[i] = fact[i - 1] * i % MOD;
    fact_rev[i] = rev(fact[i]);
  }
}
inline long long comb(long long n, long long k) {
  return fact[n] * fact_rev[k] % MOD * fact_rev[n - k] % MOD;
}
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
long long n;
vector<long long> g[MAXN];
bool f[MAXN];
long long dp[MAXN];
long long leaves[MAXN];
void dfs(long long v, long long p) {
  bool has_child = false;
  vector<long long> dps;
  for (long long to : g[v]) {
    if (to == p) continue;
    has_child = true;
    dfs(to, v);
    f[v] |= !f[to];
    dps.push_back(dp[to]);
    leaves[v] += leaves[to];
  }
  if (!has_child) {
    leaves[v] = 1;
    return;
  }
  sort(dps.begin(), dps.end(), greater<long long>());
  for (long long i = 0; i < dps.size() - 1; i++) {
    leaves[v] -= dps[i];
  }
  dp[v] = dps.back();
  if (!f[v]) {
    dp[v]--;
  } else {
    dp[v]++;
  }
}
signed main() {
  cin.tie(0);
  cout.tie(0);
  ios_base ::sync_with_stdio(0);
  long long t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (long long i = 0; i < n; i++) {
      g[i].clear();
      f[i] = false;
      dp[i] = 0;
      leaves[i] = 0;
    }
    for (long long i = 0; i < n - 1; i++) {
      long long u, v;
      cin >> u >> v;
      u--;
      v--;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    dfs(0, -1);
    cout << leaves[0] << '\n';
  }
  return 0;
}

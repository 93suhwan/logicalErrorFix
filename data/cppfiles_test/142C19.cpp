#include <bits/stdc++.h>
using namespace std;
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
mt19937_64 rang(
    chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
  uniform_int_distribution<int> uid(0, lim - 1);
  return uid(rang);
}
int mpow(int base, int exp);
void ipgraph(int n, int m);
void dfs(int u, int par);
const int mod = 1000000007;
const int N = 3e5, M = N;
vector<int> g[N];
int a[N];
void solve() {
  int i, j, n, m;
  cin >> m >> n;
  vector<vector<int> > vec(m, vector<int>(n));
  vector<int> mx(n, INT_MIN);
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      cin >> vec[i][j];
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      mx[i] = max(mx[i], vec[j][i]);
    }
  }
  for (i = 0; i < m; i++) {
    sort(vec[i].begin(), vec[i].end());
  }
  int maxi = INT_MIN;
  for (i = 0; i < m; i++) {
    maxi = max(maxi, vec[i][n - 2]);
  }
  int ans = INT_MAX;
  for (i = 0; i < n; i++) {
    ans = min(ans, mx[i]);
  }
  ans = min(ans, maxi);
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  srand(chrono::high_resolution_clock::now().time_since_epoch().count());
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
int mpow(int base, int exp) {
  base %= mod;
  int result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((long long)result * base) % mod;
    base = ((long long)base * base) % mod;
    exp >>= 1;
  }
  return result;
}
void ipgraph(int n, int m) {
  int i, u, v;
  while (m--) {
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
}
void dfs(int u, int par) {
  for (int v : g[u]) {
    if (v == par) continue;
    dfs(v, u);
  }
}

#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long long power(long long, long long);
const long long N = 2 * 1e5 + 1;
vector<long long> g[N], v(N, 0);
void dfs(long long s, long long prev) {
  long long p = 0;
  for (auto u : g[s]) {
    if (u == prev) continue;
    dfs(u, s);
    if (v[u] == 1) p = 1;
  }
  if (s == prev) return;
  if (p == 1)
    v[s] = 2;
  else
    v[s] = 1;
}
void solution() {
  long long n, a, b, f;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  v[1] = 0;
  dfs(1, 1);
  long long ans = n;
  for (int i = 1; i <= n; i++) {
    if (v[i] == 2) ans -= 2;
  }
  for (auto x : g[1]) {
    if (v[x] == 1) {
      ans--;
      break;
    }
  }
  for (int i = 1; i <= n; i++) {
    g[i].clear();
    v[i] = -1;
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solution();
  }
  return 0;
}
long long power(long long x, long long y) {
  long long res = 1;
  x = x % mod;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % mod;
    y = y >> 1;
    x = (x * x) % mod;
  }
  return res;
}

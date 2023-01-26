#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long inv(long long i) {
  if (i == 1) return 1;
  return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;
}
long long mod_mul(long long a, long long b) {
  a = a % mod;
  b = b % mod;
  return (((a * b) % mod) + mod) % mod;
}
long long mod_add(long long a, long long b) {
  a = a % mod;
  b = b % mod;
  return (((a + b) % mod) + mod) % mod;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long ceil_div(long long a, long long b) {
  return a % b == 0 ? a / b : a / b + 1;
}
long long pwr(long long a, long long b) {
  a %= mod;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
vector<bool> visted;
bool ok;
vector<vector<pair<long long, long long>>> adj;
vector<pair<long long, long long>> unknown;
vector<vector<long long>> ans;
vector<long long> r;
void dfs(long long curr_node, long long val) {
  visted[curr_node] = true;
  r[curr_node] = val;
  for (auto x : adj[curr_node]) {
    if (visted[x.first]) {
      if ((val ^ x.second) != r[x.first]) {
        ok = false;
      }
    } else {
      dfs(x.first, val ^ x.second);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t, n, i, j, temp, sum, m, u, v, w;
  string sans;
  t = 1;
  cin >> t;
  while (t--) {
    sans = "NO";
    temp = sum = 0;
    cin >> n >> m;
    visted.assign(n + 1, false);
    ok = true;
    adj.assign(n + 1, {});
    unknown.clear();
    ans.clear();
    r.assign(n + 1, 0);
    for (i = 1; i <= n - 1; i++) {
      cin >> u >> v >> w;
      if (w == -1) {
        unknown.push_back({u, v});
      } else {
        temp = (__builtin_popcount(w)) % 2;
        adj[u].push_back({v, temp});
        adj[v].push_back({u, temp});
        ans.push_back({u, v, w});
      }
    }
    for (i = 1; i <= m; i++) {
      cin >> u >> v >> w;
      temp = w;
      adj[u].push_back({v, temp});
      adj[v].push_back({u, temp});
    }
    if (!ok) {
      cout << "NO\n";
      continue;
    }
    for (i = 1; i <= n; i++) {
      if (!visted[i]) {
        dfs(i, 0LL);
      }
    }
    if (!ok) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      for (auto edge : unknown) {
        ans.push_back(
            {edge.first, edge.second, (r[edge.first] ^ r[edge.second])});
      }
      for (auto x : ans) {
        cout << x[0] << " " << x[1] << " " << x[2] << "\n";
      }
    }
  }
  return 0;
}

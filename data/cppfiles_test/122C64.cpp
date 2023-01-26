#include <bits/stdc++.h>
using namespace std;
long long long long binExp(long long long long x, long long long long n,
                           long long long long m) {
  long long long long res = 1;
  while (n) {
    if (n & 1) res = (res * x) % m;
    x = (x * x) % m;
    n >>= 1;
  }
  return res;
}
long long long long modInv(long long long long i, long long long long m) {
  return binExp(i, m - 2, m);
}
long long long long add(long long long long a, long long long long b) {
  long long long long res = a + b;
  if (res >= 1000000007) res -= 1000000007;
  if (res < 0) res += 1000000007;
  return res;
}
long long long long mul(long long long long a, long long long long b) {
  long long long long res = (a) * (b);
  res %= 1000000007;
  if (res < 0) res += 1000000007;
  return res;
}
vector<pair<long long, long long>> adj[200005];
bool vis[200005];
long long val[200005];
bool poss;
void dfs(long long v, bool z) {
  if (vis[v]) {
    if (val[v] != z) poss = false;
    return;
  }
  vis[v] = true;
  val[v] = z;
  for (auto x : adj[v]) {
    if (x.second != -1) {
      dfs(x.first, z ^ (__builtin_popcount(x.second) & 1));
    }
  }
}
void solve(long long tc = 0) {
  long long n, m;
  cin >> n >> m;
  poss = true;
  for (long long i = 1; i <= n; i++) {
    adj[i].clear();
    vis[i] = false;
  }
  vector<pair<pair<long long, long long>, long long>> edges;
  long long x, y, v;
  for (long long i = 0; i < n - 1; i++) {
    cin >> x >> y >> v;
    adj[x].push_back({y, v});
    adj[y].push_back({x, v});
    edges.push_back({{x, y}, v});
  }
  for (long long i = 0; i < m; i++) {
    cin >> x >> y >> v;
    adj[x].push_back({y, v});
    adj[y].push_back({x, v});
  }
  for (long long i = 1; i <= n; i++) {
    if (!vis[i]) {
      dfs(i, 0);
    }
  }
  if (!poss) return void(cout << "NO\n");
  cout << "YES\n";
  for (auto z : edges) {
    long long a = z.first.first;
    long long b = z.first.second;
    cout << a << ' ' << b << ' '
         << (z.second == -1 ? (val[a] ^ val[b]) : z.second) << '\n';
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  clock_t start, end;
  start = clock();
  long long tc;
  tc = 1;
  cin >> tc;
  for (long long i = 1; i <= tc; i++) solve(i);
  end = clock();
  double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
}

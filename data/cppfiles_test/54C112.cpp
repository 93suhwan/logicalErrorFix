#include <bits/stdc++.h>
using namespace std;
long long M = 1e9 + 7;
double pi = acos(-1.0);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long powerm(long long x, long long y) {
  long long res = 1;
  while (y) {
    if (y & 1) res = (res * x) % M;
    y = y >> 1;
    x = (x * x) % M;
  }
  return res % M;
}
long long power(long long x, long long y) {
  long long res = 1;
  while (y) {
    if (y & 1) res = (res * x);
    y = y >> 1;
    x = (x * x);
  }
  return res;
}
long long gcd(long long a, long long b) {
  if (b > a) return gcd(b, a);
  if (b == 0) return a;
  return gcd(b, a % b);
}
const int N = 7e5 + 500;
vector<pair<int, int> > adj[N];
vector<int> col(N);
vector<bool> vis(N);
vector<int> cnt(2);
bool ok;
void dfs(int u, int n) {
  vis[u] = true;
  cnt[col[u]]++;
  for (pair<int, int> it : adj[u]) {
    if (vis[it.first]) {
      if ((col[it.first] ^ it.second) != col[u]) ok = 0;
    } else {
      col[it.first] = col[u] ^ it.second;
      dfs(it.first, n);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      adj[i].clear();
      col[i] = -1;
      vis[i] = false;
    }
    for (int i = 0; i < m; i++) {
      int u, v;
      string s;
      cin >> u >> v >> s;
      if (s == "imposter")
        adj[u].push_back({v, 1}), adj[v].push_back({u, 1});
      else {
        adj[u].push_back({v, 0});
        adj[v].push_back({u, 0});
      }
    }
    int ans = 0;
    ok = 1;
    for (int i = 1; i <= n; i++) {
      if (vis[i]) continue;
      col[i] = 0;
      cnt[0] = cnt[1] = 0;
      dfs(i, n);
      ans += max(cnt[0], cnt[1]);
    }
    if (!ok) ans = -1;
    cout << ans << '\n';
  }
  return 0;
}

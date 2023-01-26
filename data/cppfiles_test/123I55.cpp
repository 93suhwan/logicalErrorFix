#include <bits/stdc++.h>
using namespace std;
void setIn(string s) { freopen(s.c_str(), "r", stdin); }
void setOut(string s) { freopen(s.c_str(), "w", stdout); }
void setIO(string s = "") {
  if ((int)(s.size())) {
    setIn(s + ".in"), setOut(s + ".out");
  }
}
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l, int r) { return uniform_int_distribution<int>(l, r)(gen); }
const int N = 2e5 + 5;
int n, k;
vector<int> g[N];
int d[N];
int who[N];
int par[N];
void dfs(int v, int from = 0) {
  if (from) g[v].erase(find(g[v].begin(), g[v].end(), from));
  par[v] = from;
  d[v] = 1;
  who[v] = v;
  for (int to : g[v]) {
    dfs(to, v);
    if (d[v] < d[to] + 1) {
      d[v] = d[to] + 1;
      who[v] = who[to];
    }
  }
}
int used[N];
void solve() {
  cin >> n >> k;
  for (int i = 1, a, b; i < n; ++i) {
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(1);
  priority_queue<int> pq;
  for (int v = 1; v <= n; ++v) {
    if (used[v]) continue;
    int x = who[v];
    pq.push(d[v]);
    while (x != par[v]) {
      used[x] = 1;
      x = par[x];
    }
  }
  int subtree = 0;
  long long ans = -1e18;
  for (int r = 0; r <= k; ++r) {
    int b = min(n / 2, n - subtree);
    ans = max(ans, (n - r - b) * (long long)(r - b));
    if ((int)(pq.size())) {
      subtree += pq.top();
      pq.pop();
    }
  }
  cout << ans << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int TestCases = 1;
  for (int TestCase = 1; TestCase <= TestCases; ++TestCase) {
    solve();
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const long long INF = 1LL << 52;
const int MAXN = 4e6 + 9;
vector<int> a;
int n;
unordered_map<int, int> x2i;
vector<int> adj[MAXN];
int msb(int x) {
  if (x == 0) return 0;
  return 32 - __builtin_clz((unsigned)x);
}
int dist[MAXN];
void dfs(int x, int p) {
  for (int i : adj[x]) {
    if (i == p) continue;
    dist[i] = dist[x] + 1;
    dfs(i, x);
  }
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    x2i[a[i]] = i;
  }
  for (int i = 0; i < n; i++) {
    int cur = a[i];
    int u = i;
    while (cur) {
      int nxt = (1 << msb(cur - 1)) - cur;
      assert(nxt < cur);
      int v;
      if (!x2i.count(nxt)) {
        v = x2i[nxt] = a.size();
        a.push_back(nxt);
      } else {
        v = x2i[nxt];
      }
      adj[u].push_back(v);
      adj[v].push_back(u);
      u = v;
      cur = nxt;
    }
  }
  for (int i = 0; i < (int)a.size(); i++) {
    sort(adj[i].begin(), adj[i].end());
    adj[i].resize(unique(adj[i].begin(), adj[i].end()) - adj[i].begin());
  }
  dist[0] = 0;
  dfs(0, -1);
  int ans1 = 0, ans2 = 0;
  for (int i = 0; i < n; i++) {
    if (dist[i] > dist[ans1]) {
      ans1 = i;
    }
  }
  dist[ans1] = 0;
  dfs(ans1, -1);
  for (int i = 0; i < n; i++) {
    if (dist[i] > dist[ans2]) {
      ans2 = i;
    }
  }
  cout << ans1 + 1 << ' ' << ans2 + 1 << ' ' << dist[ans2] << '\n';
}

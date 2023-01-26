#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 3, Mod = 1e9 + 7;
const int maxN = 2e5 + 3;
bool visit1[maxN];
bool visit2[maxN];
vector<pair<long long, long long>> adj[maxN];
long long stat[maxN];
bool out = 0;
bool chk(long long u, pair<long long, long long> v) {
  if (v.second < 0) {
    if (stat[v.first] == 1 && v.second * -1 == stat[u])
      return 0;
    else if (stat[v.first] == 2 && v.second * -1 != stat[u])
      return 0;
    else
      return 1;
  } else {
    if (stat[u] == 1 && v.second == stat[v.first])
      return 0;
    else if (stat[u] == 2 && v.second != stat[v.first])
      return 0;
    else
      return 1;
  }
}
long long dfs1(long long u, long long k) {
  if (out) return 0;
  long long ret = 0;
  if (k == 2) ret = 1;
  visit1[u] = 1;
  stat[u] = k;
  for (auto v : adj[u]) {
    if (visit1[v.first]) {
      if (chk(u, v)) {
        out = 1;
        return 0;
      }
      continue;
    }
    if (v.second < 0) {
      if (v.second * -1 == k)
        ret += dfs1(v.first, 1);
      else
        ret += dfs1(v.first, 2);
    } else {
      if (k == 1)
        ret += dfs1(v.first, v.second);
      else if (v.second == 2)
        ret += dfs1(v.first, 1);
      else
        ret += dfs1(v.first, 2);
    }
  }
  return ret;
}
long long dfs2(long long u, long long k) {
  if (out) return 0;
  long long ret = 0;
  if (k == 2) ret = 1;
  visit2[u] = 1;
  stat[u] = k;
  for (auto v : adj[u]) {
    if (visit2[v.first]) {
      continue;
    }
    if (v.second < 0) {
      if (v.second * -1 == k)
        ret += dfs2(v.first, 1);
      else
        ret += dfs2(v.first, 2);
    } else {
      if (k == 1)
        ret += dfs2(v.first, v.second);
      else if (v.second == 2)
        ret += dfs2(v.first, 1);
      else
        ret += dfs2(v.first, 2);
    }
  }
  return ret;
}
void solve() {
  out = 0;
  long long n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    visit1[i] = 0;
    visit2[i] = 0;
    adj[i].clear();
    stat[i] = -1;
  }
  for (int i = 0; i < m; i++) {
    long long x, y;
    cin >> x >> y;
    x--;
    y--;
    string s;
    cin >> s;
    long long k = 1;
    if (s == "imposter")
      k = 2;
    else if (s == "crewmate")
      k = 1;
    adj[x].push_back(make_pair(y, k));
    adj[y].push_back(make_pair(x, -1 * k));
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    if (!visit1[i]) ans += max(dfs1(i, 1), dfs2(i, 2));
  }
  for (int i = 0; i < n; i++) {
    if (!visit1[i]) ans++;
  }
  if (out) ans = -1;
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }
}

#include <bits/stdc++.h>
using namespace std;
const long long N = 1e3 + 5;
vector<set<long long>> s1(N), s2(N);
bool vis[N];
long long val1[N];
long long val2[N];
void dfs1(long long u, long long p) {
  vis[u] = true;
  val1[u] = p;
  for (auto &v : s1[u]) {
    if (!vis[v]) {
      dfs1(v, p);
    }
  }
}
void dfs2(long long u, long long p) {
  vis[u] = true;
  val2[u] = p;
  for (auto &v : s2[u]) {
    if (!vis[v]) {
      dfs2(v, p);
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, m1, m2;
  cin >> n >> m1 >> m2;
  for (long long i = 0; i < n + 1; i++) {
    vis[i] = false;
    s2[i].clear();
    s1[i].clear();
  }
  long long u, v;
  for (long long i = 0; i < m1; i++) {
    cin >> u >> v;
    s1[u].insert(v);
    s1[v].insert(u);
  }
  for (long long i = 0; i < m2; i++) {
    cin >> u >> v;
    s2[u].insert(v);
    s2[v].insert(u);
  }
  long long p = 1;
  for (long long i = 1; i < n + 1; i++) {
    if (!vis[i]) {
      dfs1(i, p);
      p++;
    }
  }
  for (long long i = 1; i < n + 1; i++) vis[i] = false;
  p = 1;
  for (long long i = 1; i < n + 1; i++) {
    if (!vis[i]) {
      dfs2(i, p);
      p++;
    }
  }
  vector<pair<long, long>> ans;
  set<long long> st1, st2;
  for (long long i = 1; i < n; i++) {
    for (long long j = i + 1; j < n + 1; j++) {
      if (val1[i] != val1[j] && val2[i] != val2[j] &&
          !(st1.count(val1[j]) && st1.count(val1[i])) &&
          !(st2.count(val2[j]) && st2.count(val2[i]))) {
        st1.insert(val1[j]);
        st2.insert(val2[j]);
        ans.push_back({i, j});
        st1.insert(val1[i]);
        st2.insert(val2[i]);
      }
    }
  }
  cout << ans.size() << "\n";
  for (long long i = 0; i < ans.size(); i++) {
    cout << ans[i].first << " " << ans[i].second << "\n";
  }
  return 0;
}

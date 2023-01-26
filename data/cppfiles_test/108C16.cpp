#include <bits/stdc++.h>
using namespace std;
vector<vector<long long>> g;
vector<bool> used;
void dfs(long long v) {
  used[v] = true;
  for (auto to : g[v])
    if (!used[to]) dfs(to);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    g.resize(n);
    vector<pair<long long, long long>> a(n), b(n);
    used.resize(n, false);
    for (int i = 0; i < n; i++) {
      cin >> a[i].first;
      a[i].second = i;
    }
    for (int i = 0; i < n; i++) {
      cin >> b[i].first;
      b[i].second = i;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i = 0; i < n - 1; i++) {
      g[a[i].second].push_back(a[i + 1].second);
      g[b[i].second].push_back(b[i + 1].second);
    }
    dfs(a[n - 1].second);
    dfs(b[n - 1].second);
    string ans = "";
    for (int i = 0; i < n; i++) ans += '0';
    for (int i = 0; i < n; i++)
      if (used[i]) ans[i] = '1';
    cout << ans << endl;
    g.clear();
    used.clear();
  }
}

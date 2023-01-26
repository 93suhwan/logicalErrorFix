#include <bits/stdc++.h>
using namespace std;
vector<vector<long long>> g;
void createGraph(vector<long long> mn, vector<long long> mx) {
  long long n = mx.size();
  vector<pair<long long, long long>> mxId;
  for (long long i = 0; i < n; i++) mxId.push_back({mx[i], i});
  vector<pair<long long, long long>> mnId;
  for (long long i = 0; i < n; i++) mnId.push_back({mn[i], i});
  sort(mxId.begin(), mxId.end());
  for (long long i = 0; i + 1 < n; i++)
    g[mxId[i].second].push_back(mxId[i + 1].second);
  sort(mnId.begin(), mnId.end());
  for (long long i = 0, j = 0; i < n; i++) {
    while (mxId[j].first < mnId[i].first) j++;
    g[mnId[i].second].push_back(mxId[j].second);
  }
}
void dfs(long long u, vector<long long>& visit) {
  if (visit[u]++) return;
  for (long long v : g[u]) dfs(v, visit);
}
void test() {
  long long n, m;
  cin >> n >> m;
  vector<vector<long long>> a(n, vector<long long>(m));
  g.assign(n, vector<long long>());
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  vector<long long> col1(n);
  for (long long i = 0; i < n; i++) col1[i] = a[i][0];
  long long ib = min_element(col1.begin(), col1.end()) - col1.begin();
  long long ir = max_element(col1.begin(), col1.end()) - col1.begin();
  long long k = 0;
  while (k < m and a[ir][k] > a[ib][k]) k++;
  if (k == m || k == 0) {
    cout << "NO" << '\n';
    return;
  }
  vector<long long> mn1(n), mx1(n);
  for (long long i = 0; i < n; i++) {
    mn1[i] = *min_element(a[i].begin(), a[i].begin() + k);
    mx1[i] = *max_element(a[i].begin(), a[i].begin() + k);
  }
  vector<long long> mn2(n), mx2(n);
  for (long long i = 0; i < n; i++) {
    mn2[i] = -*max_element(a[i].begin() + k, a[i].end());
    mx2[i] = -*min_element(a[i].begin() + k, a[i].end());
  }
  createGraph(mn1, mx1);
  createGraph(mn2, mx2);
  vector<long long> visit(n);
  dfs(ir, visit);
  if (visit[ib]) {
    cout << "NO" << '\n';
    return;
  }
  cout << "YES" << '\n';
  for (long long i = 0; i < n; i++) {
    if (visit[i])
      cout << "R";
    else
      cout << "B";
  }
  cout << ' ' << k << '\n';
}
signed main() {
  iostream::sync_with_stdio(false);
  long long q;
  cin >> q;
  while (q--) test();
  assert(cin);
}

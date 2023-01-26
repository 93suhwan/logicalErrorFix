#include <bits/stdc++.h>
using namespace std;
void solve();
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
}
int find(vector<int> &dsuf, int x) {
  if (dsuf[x] == -1) return x;
  return dsuf[x] = find(dsuf, dsuf[x]);
}
void printv(vector<pair<int, int>> &v) {
  for (auto p : v) cout << p.first << " " << p.second << "\n";
}
void solve() {
  int n, m1, m2;
  cin >> n >> m1 >> m2;
  vector<int> dsuf1(n + 1, -1), dsuf2(n + 1, -1);
  vector<int> deg1(n + 1, 0), deg2(n + 1, 0);
  for (int i = 0; i < m1; i++) {
    int u, v;
    cin >> u >> v;
    int pa = find(dsuf1, u);
    int pb = find(dsuf1, v);
    dsuf1[pa] = pb;
    deg1[u]++;
    deg1[v]++;
  }
  for (int i = 0; i < m2; i++) {
    int u, v;
    cin >> u >> v;
    int pa = find(dsuf2, u);
    int pb = find(dsuf2, v);
    dsuf2[pa] = pb;
    deg2[u]++;
    deg2[v]++;
  }
  vector<pair<int, int>> vp;
  int j = 1;
  while (j <= n) {
    if (m1 == n - 1 or m2 == n - 1) break;
    for (int i = 2; i <= n; i++) {
      int pa1 = find(dsuf1, j);
      int pb1 = find(dsuf1, i);
      if (pa1 == pb1) continue;
      int pa2 = find(dsuf2, j);
      int pb2 = find(dsuf2, i);
      if (pa2 == pb2) continue;
      dsuf1[pa1] = pb1;
      dsuf2[pa2] = pb2;
      deg1[j]++;
      deg1[i]++;
      deg2[j]++;
      deg2[i]++;
      m1++;
      m2++;
      vp.push_back({j, i});
      if (m1 == n - 1 or m2 == n - 1) break;
    }
    int cnd = j + 1;
    for (int k = 1; k <= n; k++)
      if (deg1[k] == 0) cnd = k;
    j = cnd;
  }
  cout << vp.size() << endl;
  printv(vp);
}

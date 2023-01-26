#include <bits/stdc++.h>
using namespace std;
map<int, int> xMap;
map<int, int> yMap;
vector<pair<int, int> > row[200005], col[200005];
int x[200005], y[200005], tmr[200005], parent[200005];
int findrep(int u) {
  if (parent[u] != u) parent[u] = findrep(parent[u]);
  return parent[u];
}
void Union(int x, int y) {
  int px = findrep(x);
  int py = findrep(y);
  if (px != py) {
    parent[px] = py;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t, n, m, i, j, k;
  cin >> t;
  while (t--) {
    xMap.clear();
    yMap.clear();
    cin >> n >> k;
    for (i = 0; i <= n; i++) {
      row[i].clear();
      col[i].clear();
    }
    int id1 = 0, id2 = 0;
    for (i = 0; i < n; i++) {
      cin >> x[i] >> y[i] >> tmr[i];
      if (!xMap[x[i]]) {
        id1++;
        xMap[x[i]] = id1;
      }
      if (!yMap[y[i]]) {
        id2++;
        yMap[y[i]] = id2;
      }
      row[yMap[y[i]]].push_back({x[i], i});
      col[xMap[x[i]]].push_back({y[i], i});
    }
    for (i = 1; i <= id1; i++) sort(col[i].begin(), col[i].end());
    for (i = 1; i <= id2; i++) sort(row[i].begin(), row[i].end());
    for (i = 0; i < n; i++) parent[i] = i;
    for (i = 1; i <= id1; i++) {
      int sz = col[i].size();
      for (j = 1; j < sz; j++) {
        if (col[i][j].first - col[i][j - 1].first <= k) {
          Union(col[i][j].second, col[i][j - 1].second);
        }
      }
    }
    for (i = 1; i <= id2; i++) {
      int sz = row[i].size();
      for (j = 1; j < sz; j++) {
        if (row[i][j].first - row[i][j - 1].first <= k) {
          Union(row[i][j].second, row[i][j - 1].second);
        }
      }
    }
    for (i = 0; i < n; i++) {
      j = findrep(i);
      tmr[j] = min(tmr[j], tmr[i]);
    }
    vector<int> tt;
    for (i = 0; i < n; i++) {
      if (findrep(i) == i) tt.push_back(tmr[i]);
    }
    sort(tt.begin(), tt.end());
    int ans = -1;
    int sz = tt.size();
    for (i = sz - 1; i >= 0; i--) {
      if (tt[i] <= ans) break;
      ans++;
    }
    cout << ans << endl;
  }
}

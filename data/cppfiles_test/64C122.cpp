#include <bits/stdc++.h>
using namespace std;
int const N = 1e5 + 5;
int n, m1, m2, fa[3][N], ans, pl[N], pr[N], t1, t2;
set<int> row[N], col[N];
set<pair<int, int> > rows;
map<int, int> mp[N];
int rd() {
  int ret = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    ret = (ret << 3) + (ret << 1) + ch - '0', ch = getchar();
  return ret * f;
}
int find(int t, int x) {
  if (fa[t][x] != x) fa[t][x] = find(t, fa[t][x]);
  return fa[t][x];
}
void merge1(int x, int y) {
  for (int it : row[y]) {
    row[x].insert(it);
    col[it].erase(y);
    col[it].insert(x);
    mp[x][it] = mp[y][it];
  }
}
void merge2(int x, int y) {
  for (int it : col[y]) {
    col[x].insert(it);
    row[it].erase(y);
    row[it].insert(x);
    mp[it][x] = mp[it][y];
  }
}
int main() {
  n = rd();
  m1 = rd();
  m2 = rd();
  t1 = 1;
  t2 = 2;
  for (int t = 1; t <= 2; t++)
    for (int i = 1; i <= n; i++) fa[t][i] = i;
  for (int i = 1, x, y; i <= m1; i++) {
    x = rd();
    y = rd();
    x = find(1, x);
    y = find(1, y);
    fa[1][x] = y;
  }
  for (int i = 1, x, y; i <= m2; i++) {
    x = rd();
    y = rd();
    x = find(2, x);
    y = find(2, y);
    fa[2][x] = y;
  }
  if (m1 < m2) swap(t1, t2);
  for (int i = 1, p1, p2; i <= n; i++) {
    p1 = find(t1, i);
    p2 = find(t2, i);
    row[p1].insert(p2);
    col[p2].insert(p1);
    mp[p1][p2] = i;
  }
  for (int i = 1; i <= n; i++)
    if (find(t1, i) == i) rows.insert(make_pair(-row[i].size(), i));
  while (rows.size() > 1) {
    int x = (*rows.begin()).second;
    rows.erase(rows.begin());
    int y = (*rows.begin()).second;
    rows.erase(rows.begin());
    int a = *row[x].begin();
    int b = *row[y].begin();
    if (a == b) {
      set<int>::iterator it = row[x].begin();
      it++;
      a = *it;
    }
    ans++;
    pl[ans] = mp[x][a];
    pr[ans] = mp[y][b];
    if (col[a].size() < col[b].size()) swap(a, b);
    merge1(x, y);
    merge2(a, b);
    rows.insert(make_pair(-row[x].size(), x));
  }
  printf("%d\n", ans);
  for (int i = 1; i <= ans; i++) printf("%d %d\n", pl[i], pr[i]);
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N = 53, mod = 1e9 + 7;
int n, k;
int d[N], a[N][N];
vector<pair<int, int> > tmp;
set<pair<int, int> > edge;
int siz[N];
vector<int> g[N];
int f[N];
int fa(int x) { return f[x] == x ? x : f[x] = fa(f[x]); }
int dif;
pair<int, int> del, ad;
int f2[N];
void dfs(int x, int fat) {
  f2[x] = fat;
  for (int v : g[x])
    if (v != fat) {
      dfs(v, x);
    }
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= k; ++i) scanf("%d", d + i);
  for (int i = 1; i <= n; ++i)
    for (int j = i + 1; j <= n; ++j) scanf("%d", a[i] + j), a[j][i] = a[i][j];
  for (int i = 1; i <= n; ++i)
    for (int j = i + 1; j <= n; ++j) tmp.push_back(make_pair(i, j));
  int ans = mod;
  for (int tim = 1; tim <= 100; ++tim) {
    int now = 0;
    for (int i = 1; i <= n; ++i) f[i] = i;
    edge.clear();
    for (int i = 1; i <= n; ++i) siz[i] = 0;
    random_shuffle(begin(tmp), end(tmp));
    while ((int)edge.size() < n - 1) {
      for (auto& p : tmp) {
        if (p.first <= k && siz[p.first] == d[p.first]) continue;
        if (p.second <= k && siz[p.second] == d[p.second]) continue;
        if (p.first <= k && p.second <= k && siz[p.first] == d[p.first] - 1 &&
            siz[p.second] == d[p.second] - 1)
          continue;
        int x = fa(p.first), y = fa(p.second);
        if (x == y) continue;
        f[x] = y;
        now += a[p.first][p.second];
        ++siz[p.first];
        ++siz[p.second];
        edge.insert(p);
      }
    }
    a[0][0] = -mod;
    int cnt0 = 0;
    for (;;) {
      for (int i = 1; i <= n; ++i) g[i].clear();
      for (auto& p : edge)
        g[p.first].push_back(p.second), g[p.second].push_back(p.first);
      for (int i = 1; i <= n; ++i) siz[i] = g[i].size();
      dif = mod;
      for (int i = 1; i <= n; ++i) {
        dfs(i, 0);
        for (int j = 1; j <= n; ++j) {
          int kk = j;
          while (kk != i) {
            bool flag = 0;
            --siz[kk];
            --siz[f2[kk]];
            ++siz[i];
            ++siz[j];
            for (int p = 1; p <= k; ++p)
              if (siz[p] > d[p]) {
                flag = 1;
                break;
              }
            ++siz[kk];
            ++siz[f2[kk]];
            --siz[i];
            --siz[j];
            if (!flag && dif >= a[i][j] - a[kk][f2[kk]]) {
              dif = a[i][j] - a[kk][f2[kk]];
              del = make_pair(min(kk, f2[kk]), max(kk, f2[kk]));
              ad = make_pair(min(i, j), max(i, j));
            }
            kk = f2[kk];
          }
        }
      }
      if (dif <= 0) {
        if (dif == 0)
          ++cnt0;
        else
          cnt0 = 0;
        if (cnt0 == 10) break;
        now += dif;
        edge.erase(del);
        edge.insert(ad);
      } else
        break;
    }
    ans = min(ans, now);
  }
  printf("%d\n", ans);
  return 0;
}

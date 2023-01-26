#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
int n, q, a[150010], col[300000], pnum[1000010], mark = -1;
bool isp[1000010];
vector<int> p, g[300000], gg[300000];
void preCalc() {
  for (int i = 0; i < 1000005; ++i) isp[i] = true;
  for (int i = 2; i <= 1000001; ++i)
    if (isp[i]) {
      pnum[i] = p.size();
      p.push_back(i);
      for (int j = i + i; j <= 1000001; j += i) isp[j] = false;
    }
}
void dfs(int pos) {
  col[pos] = mark;
  for (int i = 0; i < g[pos].size(); ++i)
    if (col[g[pos][i]] == -1) dfs(g[pos][i]);
}
int main() {
  preCalc();
  cin >> n >> q;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    int x = a[i];
    for (int j = 0; j < p.size() && p[j] * p[j] <= x; ++j)
      if (x % p[j] == 0) {
        while (x % p[j] == 0) x /= p[j];
        g[j].push_back(i + p.size());
        g[i + p.size()].push_back(j);
      }
    if (x > 1)
      g[pnum[x]].push_back(i + p.size()), g[i + p.size()].push_back(pnum[x]);
  }
  for (int i = 0; i < n + p.size() + 5; ++i) col[i] = -1;
  for (int i = 0; i < n + p.size(); ++i)
    if (col[i] == -1) {
      ++mark;
      dfs(i);
    }
  for (int i = 0; i < n; ++i) {
    int x = a[i] + 1;
    vector<int> d;
    d.clear();
    for (int j = 0; j < p.size() && p[j] * p[j] <= x; ++j)
      if (x % p[j] == 0) {
        while (x % p[j] == 0) x /= p[j];
        d.push_back(j);
      }
    if (x > 1) d.push_back(pnum[x]);
    for (int j = 0; j < d.size(); ++j) {
      for (int k = j + 1; k < d.size(); ++k)
        if (col[d[j]] != col[d[k]]) {
          gg[col[d[j]]].push_back(col[d[k]]);
          gg[col[d[k]]].push_back(col[d[j]]);
        }
      if (col[i + p.size()] != col[d[j]]) {
        gg[col[i + p.size()]].push_back(col[d[j]]);
        gg[col[d[j]]].push_back(col[i + p.size()]);
      }
    }
  }
  for (int i = 0; i < n + p.size(); ++i) sort(gg[i].begin(), gg[i].end());
  int x, y;
  for (int qn = 0; qn < q; ++qn) {
    scanf("%d%d", &x, &y);
    --x;
    --y;
    if (col[x + p.size()] == col[y + p.size()]) {
      puts("0");
      continue;
    }
    int pos = lower_bound(gg[col[x + p.size()]].begin(),
                          gg[col[x + p.size()]].end(), col[y + p.size()]) -
              gg[col[x + p.size()]].begin();
    if (pos < gg[col[x + p.size()]].size() &&
        gg[col[x + p.size()]][pos] == col[y + p.size()]) {
      puts("1");
      continue;
    }
    puts("2");
  }
  return 0;
}

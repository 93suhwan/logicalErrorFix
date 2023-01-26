#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5;
const int MAXM = 3e5 + 5;
const int MAXD = 3e5 + 5;
const int mod = 998244353;
inline void add_mod(int &a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}
bool fob[MAXD];
vector<int> lef[MAXD], rig[MAXD];
inline void sort_unique(vector<int> &vec) {
  sort(vec.begin(), vec.end());
  vec.erase(unique(vec.begin(), vec.end()), vec.end());
}
void dfs_fob(int u) {
  if (fob[u]) return;
  fob[u] = 1;
  for (int x : lef[u]) dfs_fob(x);
  for (int x : rig[u]) dfs_fob(x);
}
int main(void) {
  int n, m, d;
  scanf("%d%d%d", &n, &m, &d);
  for (int i = 1; i <= n; ++i) {
    int k;
    scanf("%d", &k);
    vector<int> vec(k);
    for (int &x : vec) scanf("%d", &x);
    for (int j = 1; j < k; ++j) {
      lef[vec[j]].push_back(vec[j - 1]);
      rig[vec[j - 1]].push_back(vec[j]);
    }
  }
  for (int i = 1; i <= d; ++i) {
    sort_unique(lef[i]);
    sort_unique(rig[i]);
    if (lef[i].size() > 1 || rig[i].size() > 1) dfs_fob(i);
  }
  static bool vis[MAXD];
  map<int, int> tlens;
  for (int i = 1; i <= d; ++i)
    if (!vis[i] && !lef[i].size() && !fob[i]) {
      int cur = 0, u = i;
      while (1) {
        if (vis[u]) {
          dfs_fob(u);
          break;
        }
        ++cur;
        vis[u] = 1;
        if (rig[u].size())
          u = rig[u][0];
        else
          break;
      }
      if (!fob[i]) ++tlens[cur];
    }
  vector<pair<int, int> > lens(tlens.begin(), tlens.end());
  static int f[MAXM];
  f[0] = 1;
  for (int i = 1; i <= m; ++i)
    for (pair<int, int> &x : lens) {
      if (x.first > i) break;
      f[i] = (f[i] + (long long)f[i - x.first] * x.second) % mod;
    }
  printf("%d", f[m]);
  return 0;
}

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
int lef[MAXD], rig[MAXD];
inline void upd(int &x, int y) {
  if (x && x != y) printf("0"), exit(0);
  x = y;
}
int main(void) {
  int n, m, d;
  scanf("%d%d%d", &n, &m, &d);
  for (int i = 1; i <= n; ++i) {
    int k;
    scanf("%d", &k);
    vector<int> vec(k);
    for (int &x : vec) scanf("%d", &x);
    if (set<int>(vec.begin(), vec.end()).size() != vec.size())
      return printf("0"), 0;
    for (int j = 1; j < k; ++j) {
      upd(lef[vec[j]], vec[j - 1]);
      upd(rig[vec[j - 1]], vec[j]);
    }
  }
  static bool vis[MAXD];
  map<int, int> tlens;
  for (int i = 1; i <= d; ++i)
    if (!vis[i] && !lef[i]) {
      int cur = 0, u = i;
      while (u) {
        if (vis[u]) printf("0"), exit(0);
        ++cur;
        vis[u] = 1;
        u = rig[u];
      }
      ++tlens[cur];
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

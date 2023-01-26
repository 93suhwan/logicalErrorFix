#include <bits/stdc++.h>
#pragma optimize(3, "Ofast")
using namespace std;
const int maxn = 5e5 + 3, maxm = 1e6 + 11, inf_int = 0x3f3f3f3f;
const long long inf_ll = 0x3f3f3f3f3f3f3f;
const double eps = 1e-6;
vector<set<int>> e;
int n, top, flag;
unordered_map<long long, long long> vis, id, val;
pair<int, int> a[maxn];
inline int ID(long long x) {
  if (!id.count(x)) return val[id[x] = ++top] = x, top;
  return id[x];
}
inline pair<int, int> dfs(int x, int fa, int dep) {
  pair<int, int> ret = make_pair(x, dep);
  for (const int& v : e[x]) {
    if (v == fa) continue;
    pair<int, int> tmp = dfs(v, x, dep + 1);
    if (ret.second < tmp.second) ret = tmp;
  }
  return ret;
}
inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i].first, a[i].second = i;
  sort(a, a + 1 + n);
  e.assign(64 * n, set<int>());
  for (int i = 0; i <= n; i++) {
    if (!vis[a[i].first]) {
      flag++, vis[a[i].first] = a[i].second;
      long long lim = 1, tmp = a[i].first;
      while (lim < tmp) lim <<= 1;
      while (tmp > 0) {
        e[ID(tmp)].insert(ID(lim - tmp)), e[ID(lim - tmp)].insert(ID(tmp));
        tmp = lim - tmp;
        while (lim / 2 >= tmp && tmp > 0) lim >>= 1;
      }
    }
  }
  pair<int, int> it1 = dfs(ID(0), -1, 0);
  pair<int, int> it2 = dfs(it1.first, -1, 0);
  int x = vis[val[it1.first]], y = vis[val[it2.first]];
  cout << x << " " << y << " " << it2.second << endl;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int TEST = 1;
  while (TEST--) solve();
}

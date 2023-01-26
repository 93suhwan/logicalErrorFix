#include <bits/stdc++.h>
using namespace std;
const int N = 6e6 + 5, M = 2e5 + 5;
int n, tot, a[M], dep[N];
vector<int> G[N];
unordered_map<int, int> mp;
inline int op(int x) {
  int pw = log2(x);
  if ((1 << pw) >= x) return (1 << pw) - x;
  return (1 << pw + 1) - x;
}
inline void dfs(int x, int fa) {
  dep[x] = fa ? dep[fa] + 1 : 0;
  for (auto y : G[x])
    if (y ^ fa) dfs(y, x);
}
int main() {
  scanf("%d", &n), mp[0] = tot = 1;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    int p = a[i];
    if (mp[p]) continue;
    mp[p] = ++tot;
    int nxt = op(p);
    while (!mp[nxt]) {
      mp[nxt] = ++tot, G[mp[nxt]].emplace_back(mp[p]),
      G[mp[p]].emplace_back(mp[nxt]);
      p = nxt, nxt = op(p);
    }
    G[mp[nxt]].emplace_back(mp[p]), G[mp[p]].emplace_back(mp[nxt]);
  }
  dfs(mp[a[1]], 0);
  int p = 1;
  for (int i = 2; i <= n; ++i)
    if (dep[mp[a[i]]] > dep[mp[a[p]]]) p = i;
  dfs(mp[a[p]], 0);
  int q = 1;
  for (int i = 2; i <= n; ++i)
    if (dep[mp[a[i]]] > dep[mp[a[q]]]) q = i;
  return printf("%d %d %d\n", p, q, dep[mp[a[q]]]), 0;
}

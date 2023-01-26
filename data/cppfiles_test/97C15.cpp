#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using cmp = complex<int>;
const int N = 2e5 + 5;
int n, q, ans[N];
vector<int> G[N];
vector<pair<int, int>> Q[N];
vector<cmp> f[N];
int slp(const cmp& a) { return imag(a) / real(a); }
void dfs(int u, int fa) {
  for (int v : G[u])
    if (v != fa) {
      dfs(v, u);
      vector<cmp> t;
      swap(t, f[u]);
      for (int i = 0, j = 0; i < int((t).size()) || j < int((f[v]).size());)
        if (j == int((f[v]).size()) ||
            (i < int((t).size()) && slp(t[i]) <= slp(f[v][j])))
          f[u].push_back(t[i++]);
        else if (i && slp(f[u].back()) == slp(f[v][j]))
          f[u].back() += f[v][j++];
        else
          f[u].push_back(f[v][j++]);
    }
  for (auto [k, i] : Q[u]) {
    cmp sum;
    for (const cmp& x : f[u])
      if (slp(x) >= k) sum += x;
    ans[i] = imag(sum) + int((G[u]).size()) - (u > 1) - k * real(sum);
  }
  cmp t(1, int((G[u]).size()) - (u > 1) - 1);
  while (int((f[u]).size()) && slp(t) <= slp(f[u].back()))
    t += f[u].back(), f[u].pop_back();
  if (imag(t) > 0) f[u].push_back(t);
}
int main() {
  cin >> n;
  int u, v;
  for (int i = (2); i <= (n); i++)
    scanf("%d%d", &u, &v), G[u].push_back(v), G[v].push_back(u);
  cin >> q;
  for (int i = (1); i <= (q); i++)
    scanf("%d%d", &u, &v), Q[u].emplace_back(v, i);
  dfs(1, 0);
  for (int i = (1); i <= (q); i++) printf("%d\n", ans[i]);
}

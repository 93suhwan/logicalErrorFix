#include <bits/stdc++.h>
#pragma GCC optimize("O3")
const double PI = acos(-1);
template <class A, class B>
std::ostream& operator<<(std::ostream& st, const std::pair<A, B> p) {
  st << "(" << p.first << ", " << p.second << ")";
  return st;
}
void tc();
auto test_cases = []() {
  int T;
  scanf("%d", &T);
  while (T--) tc();
};
using namespace std;
const int mod = 998244353;
int add(int a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  if (a < 0) a += mod;
  return a;
}
int mul(int a, int b) { return (a * (long long)b) % mod; }
vector<std::vector<int> > G;
int n;
std::pair<int, int> dfs(int u, int p, int m) {
  int ctr = 0;
  for (int v : G[u])
    if (v != p) {
      auto [c, e] = dfs(v, u, m);
      if (!c) return std::pair<int, int>(0, 0);
      ctr += 1 - e;
    }
  if (ctr % m == 0) return std::pair<int, int>(1, 0);
  if ((ctr + 1) % m == 0) return std::pair<int, int>(1, 1);
  return std::pair<int, int>(0, 0);
}
int solve(int k) {
  if ((n - 1) % k) return 0;
  if (k == 1) {
    int ret = 1;
    for (int i = 0; i < (n - 1); i++) ret = mul(ret, 2);
    return ret;
  }
  return dfs(1, 0, k).first;
}
int g[1 << 20];
void tc() {
  scanf("%d", &n);
  G.clear();
  G.resize(n + 1);
  for (int e = 0; e < (n - 1); e++) {
    int a, b;
    scanf("%d %d", &a, &b);
    G[a].push_back(b);
    G[b].push_back(a);
  }
  for (int k = n; k >= 1; k--) {
    g[k] = solve(k);
    for (int s = 2 * k; s <= n; s += k) g[k] = add(g[k], -g[s]);
  }
  for (int k = 1; k <= n; k++) printf("%d%c", g[k], " \n"[k == n]);
}
int main() {
  test_cases();
  return 0;
}

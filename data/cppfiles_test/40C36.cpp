#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  char c = getchar();
  long long first = 0;
  bool f = 0;
  for (; !isdigit(c); c = getchar()) f ^= !(c ^ 45);
  for (; isdigit(c); c = getchar())
    first = (first << 1) + (first << 3) + (c ^ 48);
  if (f) first = -first;
  return first;
}
const long long M = 3e5 + 10;
long long cnt[M], f[M], ff[M], de[M], u[M], v[M], n, m, q;
long long v1[M], v2[M];
vector<long long> e[M];
long long find(long long first) {
  return f[first] == first ? first : f[first] = find(f[first]);
}
void dfs(long long u, long long fa) {
  ff[u] = fa, de[u] = de[fa] + 1;
  for (long long i = 0; i < e[u].size(); i++) {
    long long to = e[u][i];
    if (to != fa) dfs(to, u);
  }
}
long long LCA(long long u, long long v) {
  if (de[u] < de[v]) swap(u, v);
  while (de[u] != de[v]) u = ff[u];
  while (u != v) u = ff[u], v = ff[v];
  return v;
}
void work(long long u, long long v) {
  long long f = 1, cnt1 = 0, cnt2 = 0;
  if (de[u] < de[v]) swap(u, v), f = -1;
  long long lca = LCA(u, v);
  while (u != lca) v1[++cnt1] = u, u = ff[u];
  while (v != lca) v2[++cnt2] = v, v = ff[v];
  v2[++cnt2] = lca;
  for (long long i = cnt2; i >= 1; i--) v1[++cnt1] = v2[i];
  cout << cnt1 << endl;
  if (f == -1)
    for (long long i = cnt1; i >= 1; i--) cout << v1[i] << ' ';
  else
    for (long long i = 1; i <= cnt1; i++) cout << v1[i] << ' ';
  puts("");
}
signed main() {
  n = read(), m = read();
  for (long long i = 1; i <= n; i++) f[i] = i;
  for (long long i = 1; i <= m; i++) {
    long long u = read(), v = read();
    if (find(u) != find(v))
      f[find(u)] = find(v), e[u].push_back(v), e[v].push_back(u);
  }
  dfs(1, 0);
  q = read();
  for (long long i = 1; i <= q; i++)
    u[i] = read(), v[i] = read(), cnt[u[i]]++, cnt[v[i]]++;
  long long res = 0;
  for (long long i = 1; i <= n; i++) res += cnt[i] & 1;
  if (res != 0) {
    puts("NO");
    cout << res / 2 << endl;
    return 0;
  }
  puts("YES");
  for (long long i = 1; i <= q; i++) work(u[i], v[i]);
  return 0;
}

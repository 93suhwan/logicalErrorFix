#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
void fileio(const string &s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}
const long long INF = 4e18;
inline long long read() {
  long long x = 0;
  bool flag = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') flag = 0;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + c - '0';
    c = getchar();
  }
  return (flag ? x : ~(x - 1));
}
long long n, m, q, top, stk[300001], fa[300001], d[300001];
vector<long long> G[300001], ans[300001];
bool dfs(long long x, long long fa, long long tar) {
  stk[++top] = x;
  if (x == tar) return 1;
  for (long long i : G[x])
    if (i != fa)
      if (dfs(i, x, tar)) return 1;
  top--;
  return 0;
}
long long find(long long x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
signed main() {
  n = read();
  m = read();
  for (long long i = 1; i <= n; i++) fa[i] = i;
  while (m--) {
    long long x = read(), y = read();
    if (find(x) != find(y)) {
      fa[find(x)] = find(y);
      G[x].push_back(y);
      G[y].push_back(x);
    }
  }
  q = read();
  for (long long i = 1; i <= q; i++) {
    long long x = read(), y = read();
    top = 0;
    dfs(x, 0, y);
    for (long long l = 1; l <= top; l++) ans[i].push_back(stk[l]);
    d[x] ^= 1;
    d[y] ^= 1;
  }
  long long res = 0;
  for (long long i = 1; i <= n; i++) res += d[i];
  if (res) {
    puts("No");
    cout << res / 2;
    return 0;
  }
  puts("Yes");
  for (long long i = 1; i <= q; i++) {
    cout << ans[i].size() << endl;
    for (long long l : ans[i]) cout << l << " ";
    cout << endl;
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
int n, k, ss, dfns;
int l[maxn], r[maxn], cst[maxn], vis[maxn], st[maxn], ok[maxn];
string s;
void dfs(int x) {
  if (x == 0) return;
  dfs(l[x]), st[++ss] = x, dfs(r[x]);
}
void down(int x) {
  if (x == 0) return;
  if (cst[x] > k) return;
  cst[l[x]] = cst[x] + 1, down(l[x]);
  if (vis[l[x]])
    vis[x] = 1;
  else if (ok[x])
    k -= cst[x], vis[x] = 1;
  if (vis[x]) cst[r[x]] = 1, down(r[x]);
}
int main() {
  scanf("%d%d", &n, &k), cin >> s, s = " " + s;
  for (int i = 1; i <= n; i++) scanf("%d%d", &l[i], &r[i]);
  dfs(1);
  for (int i = n - 1; i >= 1; i--) {
    ok[st[i]] = ok[st[i + 1]];
    if (s[st[i]] > s[st[i + 1]]) ok[st[i]] = 0;
    if (s[st[i]] < s[st[i + 1]]) ok[st[i]] = 1;
  }
  cst[1] = 1, down(1);
  for (int i = 1; i <= n; i++) {
    putchar(s[st[i]]);
    if (vis[st[i]]) putchar(s[st[i]]);
  }
  return 0;
}

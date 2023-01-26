#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') x = x * 10ll + ch - '0', ch = getchar();
  return x * f;
}
int n, k, lc[N], rc[N], a[N], id, dep[N], dfn, L[N], R[N], fa[N];
char d[N];
bool v[N];
string str, s;
long long o[N];
void add(int x, long long v) {
  for (; x <= n; x += (x & (-x))) o[x] += v;
}
void Add(int l, int r, long long v) { add(l, v), add(r + 1, -v); }
long long query(int x) {
  long long t = 0;
  for (; x; x -= (x & (-x))) t += o[x];
  return t;
}
void dfs1(int x) {
  if (lc[x]) dep[lc[x]] = dep[x] + 1, dfs1(lc[x]);
  s += str[x - 1];
  a[++id] = x;
  if (rc[x]) dep[rc[x]] = dep[x] + 1, dfs1(rc[x]);
}
void dfs2(int x) {
  L[x] = ++dfn;
  if (lc[x]) dfs2(lc[x]);
  if (rc[x]) dfs2(rc[x]);
  R[x] = dfn;
}
void dfs3(int x) {
  if (lc[x]) dfs3(lc[x]);
  putchar(str[x - 1]);
  if (v[x]) putchar(str[x - 1]);
  if (rc[x]) dfs3(rc[x]);
}
int main() {
  n = read(), k = read();
  cin >> str;
  for (int i = 1; i <= n; i++) {
    lc[i] = read(), rc[i] = read();
    if (lc[i]) fa[lc[i]] = i;
    if (rc[i]) fa[rc[i]] = i;
  }
  s += '#';
  dfs1(1);
  s += ' ';
  d[n] = ' ';
  for (int i = n - 1; i; i--)
    if (s[i] == s[i + 1])
      d[i] = d[i + 1];
    else
      d[i] = s[i + 1];
  dfs2(1);
  for (int i = 1; i <= n; i++) Add(L[i], L[i], dep[i] + 1);
  for (int i = 1; i <= n; i++)
    if (s[i] < d[i] && query(L[a[i]]) <= k) {
      int t = a[i];
      while (t && !v[t]) {
        v[t] = true;
        k--;
        Add(L[t], R[t], -1);
        t = fa[t];
      }
    } else if (s[i] > d[i])
      Add(L[a[i]], R[a[i]], n + 1);
  dfs3(1);
  return 0;
}

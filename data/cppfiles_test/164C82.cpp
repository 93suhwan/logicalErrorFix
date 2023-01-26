#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int t, n, k;
int ls[200005], rs[200005];
char s[200005];
vector<int> q;
void dfs(int x) {
  if (ls[x]) dfs(ls[x]);
  q.push_back(x);
  if (rs[x]) dfs(rs[x]);
}
int nxt[200005];
bool ok[200005], db[200005];
bool dfsls(int x, int k) {
  if (!k) return 0;
  if (ok[x]) return 1;
  if (ls[x]) return dfsls(ls[x], k - 1);
  return 0;
}
void dfs2(int x, bool r, string &ans) {
  if (r) ok[x] |= dfsls(x, k);
  ok[x] &= r;
  if (ok[x] && k) k--, db[x] = 1;
  if (ls[x]) {
    dfs2(ls[x], db[x], ans);
  }
  ans += s[x];
  if (db[x]) ans += s[x];
  if (rs[x]) dfs2(rs[x], db[x], ans);
  return;
}
int main() {
  n = read(), k = read();
  scanf("%s", s + 1);
  for (int i = 1; i <= n; i++) ls[i] = read(), rs[i] = read();
  dfs(1);
  q.push_back(0);
  for (int i = q.size() - 2; i >= 0; i--) {
    if (s[q[i]] == s[q[i + 1]])
      nxt[i] = nxt[i + 1];
    else
      nxt[i] = i + 1;
  }
  for (int i = 0; i < q.size() - 1; i++) {
    if (s[q[nxt[i]]] > s[q[i]]) ok[q[i]] = 1;
  }
  string ans = "";
  dfs2(1, 1, ans);
  cout << ans;
  return 0;
}

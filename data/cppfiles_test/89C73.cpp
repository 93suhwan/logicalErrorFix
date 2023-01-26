#include <bits/stdc++.h>
inline char nc() {
  static char buf[99999], *l, *r;
  return l == r && (r = (l = buf) + fread(buf, 1, 99999, stdin), l == r) ? EOF
                                                                         : *l++;
}
inline void read(int& x) {
  char c = nc();
  for (; c < '0' || '9' < c; c = nc())
    ;
  for (x = 0; '0' <= c && c <= '9';
       x = (x << 3) + (x << 1) + (c ^ 48), c = nc())
    ;
}
int t, n, h[200000], e[200000 << 1], nxt[200000 << 1], ans;
struct node {
  int cnt, dep;
};
inline node dfs(const int& i, const int& f) {
  int cnt = 0, remain = 0, tot = 0;
  node k;
  bool ok = 1;
  for (int j = h[i]; j; j = nxt[j])
    if (e[j] ^ f) {
      k = dfs(e[j], i);
      cnt += k.cnt;
      ok &= !k.dep || k.dep == 1;
      remain += k.dep > 0;
      ++tot;
    }
  if (!tot) {
    ++ans;
    return (node){0, 1};
  }
  if (remain)
    return (node){cnt + tot - remain, ok ? 0 : 2};
  else
    return (node){cnt + tot - 1, 1};
}
int main() {
  for (read(t); t--;) {
    read(n);
    ans = 0;
    for (int i = 0; i < n; h[i++] = 0)
      ;
    for (int i = 1, u, v; i < n; ++i) {
      read(u);
      read(v);
      --u;
      --v;
      e[i] = v;
      nxt[i] = h[u];
      h[u] = i;
      e[i + n] = u;
      nxt[i + n] = h[v];
      h[v] = i + n;
    }
    int tmp = dfs(0, -1).cnt;
    printf("%d\n", ans - tmp);
  }
}

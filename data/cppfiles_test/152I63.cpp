#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
namespace GTI {
char gc(void) {
  const int S = 1 << 16;
  static char buf[S], *s = buf, *t = buf;
  if (s == t) t = buf + fread(s = buf, 1, S, stdin);
  if (s == t) return EOF;
  return *s++;
}
ll gti(void) {
  ll a = 0, b = 1, c = gc();
  for (; !isdigit(c); c = gc()) b ^= (c == '-');
  for (; isdigit(c); c = gc()) a = a * 10 + c - '0';
  return b ? a : -a;
}
int gts(char *s) {
  int len = 0, c = gc();
  for (; isspace(c); c = gc())
    ;
  for (; c != EOF && !isspace(c); c = gc()) s[len++] = c;
  s[len] = 0;
  return len;
}
int gtl(char *s) {
  int len = 0, c = gc();
  for (; isspace(c); c = gc())
    ;
  for (; c != EOF && c != '\n'; c = gc()) s[len++] = c;
  s[len] = 0;
  return len;
}
}  // namespace GTI
using GTI::gti;
using GTI::gtl;
using GTI::gts;
const int N = 1e6 + 500;
struct T {
  int ls, rs, fa, l, r;
} t[N];
int p[N], nxt[N][2], ans[N], id[N];
bool check(int l, int r) {
  return (nxt[l][0] >= r) || (nxt[nxt[l][0] + 1][1] >= r);
}
int tag[N];
void setans(int v, int l, int r) {
  if (!v) return;
  if (tag[v] == 0)
    for (int i = l; i <= r; i++) ans[i] = -p[i];
  else if (tag[v] == 1)
    for (int i = l; i <= r; i++) ans[i] = p[i];
  else if (tag[v] == 2) {
    int x = nxt[l][0];
    for (int i = l; i <= x; i++) ans[i] = -p[i];
    for (int i = x + 1; i <= r; i++) ans[i] = p[i];
  }
}
void getans(int v) {
  if (!t[v].fa) return;
  getans(t[v].fa);
  int u = t[v].fa, mid = id[u], l = t[u].l, r = t[u].r;
  if (v == t[u].ls) {
    ans[mid] = p[mid];
    setans(t[u].rs, mid + 1, r);
  } else if (v == t[u].rs) {
    ans[mid] = -p[mid];
    setans(t[u].ls, l, mid - 1);
  }
}
bool dfs(int v, int lv, int rv, int l, int r, int fa = 0) {
  if (lv >= v && -v >= rv) return false;
  t[v].l = l, t[v].r = r;
  if (!v) {
    getans(fa);
    int u = fa, mid = id[u], l = t[u].l, r = t[u].r;
    if (v == t[u].ls) {
      ans[mid] = p[mid];
      setans(t[u].rs, mid + 1, r);
    } else if (v == t[u].rs) {
      ans[mid] = -p[mid];
      setans(t[u].ls, l, mid - 1);
    }
    return true;
  }
  if (!t[v].ls && !t[v].rs) {
    if (lv < v)
      ans[id[v]] = v;
    else if (-v < rv)
      ans[id[v]] = -v;
    getans(v);
    return true;
  }
  int mid = id[v];
  if (lv < v || !t[v].rs) {
    if (!t[v].rs)
      return dfs(t[v].ls, lv, rv, l, mid - 1, v);
    else {
      if (nxt[mid + 1][1] >= r && p[r] <= rv)
        return tag[t[v].rs] = 1,
               dfs(t[v].ls, lv, std::min(p[mid + 1], rv), l, mid - 1, v);
      if (nxt[mid + 1][0] >= r && -p[r] <= rv)
        return tag[t[v].rs] = 0,
               dfs(t[v].ls, lv, std::min(-p[mid + 1], rv), l, mid - 1, v);
      if (check(mid + 1, r) && p[r] <= rv)
        return tag[t[v].rs] = 2,
               dfs(t[v].ls, lv, std::min(-p[mid + 1], rv), l, mid - 1, v);
    }
  }
  if (-v < rv || !t[v].ls) {
    if (!t[v].ls)
      return dfs(t[v].rs, lv, rv, mid + 1, r, v);
    else {
      if (nxt[l][0] >= mid - 1 && -p[l] >= lv)
        return tag[t[v].ls] = 0,
               dfs(t[v].rs, std::max(lv, -p[mid - 1]), rv, mid + 1, r, v);
      if (nxt[l][1] >= mid - 1 && p[l] >= lv)
        return tag[t[v].ls] = 1,
               dfs(t[v].rs, std::max(lv, p[mid - 1]), rv, mid + 1, r, v);
      if (check(l, mid - 1) && -p[l] >= lv)
        return tag[t[v].ls] = 2,
               dfs(t[v].rs, std::max(lv, p[mid - 1]), rv, mid + 1, r, v);
    }
  }
  return false;
}
int main(void) {
  for (int T = gti(); T; T--) {
    int n = gti();
    for (int i = 1; i <= n; i++) p[i] = gti(), id[p[i]] = i;
    {
      static int stk[N], top;
      top = 0;
      for (int i = 1; i <= n; i++) t[i] = {0, 0};
      for (int i = 1; i <= n; i++) {
        while (top && stk[top] < p[i]) {
          if (top > 1 && stk[top - 1] < p[i])
            t[stk[top - 1]].rs = stk[top], t[stk[top]].fa = stk[top - 1];
          else
            t[p[i]].ls = stk[top], t[stk[top]].fa = p[i];
          --top;
        }
        stk[++top] = p[i];
      }
      for (int i = top - 1; i >= 1; i--)
        t[stk[i]].rs = stk[i + 1], t[stk[i + 1]].fa = stk[i];
    }
    for (int i = n; i >= 1; i--) {
      nxt[i][0] = nxt[i][1] = i;
      if (i + 1 <= n) {
        if (-p[i + 1] > -p[i]) nxt[i][0] = nxt[i + 1][0];
        if (p[i + 1] > p[i]) nxt[i][1] = nxt[i + 1][1];
      }
    }
    if (!dfs(n, -n - 1, n + 1, 1, n))
      puts("NO");
    else {
      puts("YES");
      for (int i = 1; i <= n; i++) printf("%d%c", ans[i], " \n"[i == n]);
    }
  }
  return 0;
}

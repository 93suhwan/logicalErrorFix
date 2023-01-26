#include <bits/stdc++.h>
using namespace std;
int read() {
  char ch = getchar();
  int x = 0, pd = 0;
  while (ch < '0' || ch > '9') pd |= ch == '-', ch = getchar();
  while ('0' <= ch && ch <= '9') x = x * 10 + (ch ^ 48), ch = getchar();
  return pd ? -x : x;
}
const int maxn = 1000005;
const int inf = 0x3f3f3f3f;
int n, a[maxn];
char opt[maxn];
int mx, p[maxn], pl, g[maxn], vis[maxn];
void pre() {
  for (int i = 2; i <= mx; i++) {
    if (!vis[i]) p[++pl] = g[i] = i;
    for (int j = 1; j <= pl && i * p[j] <= mx; j++) {
      int x = p[j] * i;
      vis[x] = 1, g[x] = p[j];
      if (i % p[j] == 0) break;
    }
  }
}
int tim[maxn], T;
vector<pair<int, int> > stk[maxn];
int l[maxn];
namespace SGT {
int s[maxn << 2];
void mdf(int o, int l, int r, int x) {
  ++s[o];
  if (l == r) return;
  int mid = l + r >> 1;
  if (x <= mid)
    mdf((o << 1), l, mid, x);
  else
    mdf((o << 1 | 1), mid + 1, r, x);
}
void cover(int o, int l, int r, int L, int R) {
  if ((L <= l && r <= R) || !o[s]) {
    o[s] = 0;
    return;
  }
  int mid = l + r >> 1;
  if (L <= mid) cover((o << 1), l, mid, L, R);
  if (R > mid) cover((o << 1 | 1), mid + 1, r, L, R);
  o[s] = (o << 1)[s] + (o << 1 | 1)[s];
}
}  // namespace SGT
using namespace SGT;
int main() {
  n = read();
  for (int i = 1; i <= n; i++) mx = max(mx, a[i] = read());
  scanf("%s", opt + 1);
  pre();
  for (int i = 1; i <= n; i++)
    if (opt[i] == '*') {
      l[i] = i;
      for (int j = a[i]; j > 1;) {
        int t = g[j], cnt = 0;
        while (g[j] == t) ++cnt, j /= g[j];
        if (tim[t] != T) tim[t] = T, stk[t].clear();
        stk[t].push_back(make_pair(cnt, i));
      }
    } else {
      if (a[i] == 1) l[i] = i;
      for (int j = a[i]; j > 1;) {
        int t = g[j], cnt = 0;
        while (g[j] == t) ++cnt, j /= g[j];
        if (tim[t] != T) tim[t] = T, stk[t].clear();
        while (!stk[t].empty() && cnt > stk[t].back().first)
          cnt -= stk[t].back().first, stk[t].pop_back();
        if (!stk[t].empty()) stk[t].back().first -= cnt, cnt = 0;
        if (cnt) {
          l[i] = 0, ++T;
          break;
        } else
          l[i] = max(l[i], stk[t].back().second);
      }
    }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    mdf(1, 1, n, i);
    if (l[i] < i) cover(1, 1, n, l[i] + 1, i);
    ans += s[1];
  }
  printf("%lld\n", ans);
  return 0;
}

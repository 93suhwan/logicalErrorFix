#include <bits/stdc++.h>
using namespace std;
template <typename _T>
void rd(_T &x) {
  long long f = 1;
  x = 0;
  char s = getchar();
  while (s > '9' || s < '0') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s >= '0' && s <= '9')
    x = (x << 3) + (x << 1) + (s ^ 48), s = getchar();
  x *= f;
}
template <typename _T>
void write(_T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
  return;
}
template <class T1, class T2>
void cmin(T1 &a, T2 b) {
  a = a < b ? a : b;
}
template <class T1, class T2>
void cmax(T1 &a, T2 b) {
  a = a > b ? a : b;
}
const long long N = 2e5 + 5;
long long n, k, tot, num, son[N], mxd[N], buc[N];
long long ans = -1e18;
long long cnt, hd[N], nxt[N << 1], to[N << 1], siz[N];
void add(long long u, long long v) {
  nxt[++cnt] = hd[u], hd[u] = cnt, to[cnt] = v;
}
void dfs(long long id, long long f) {
  mxd[id] = 1;
  for (long long i = hd[id]; i; i = nxt[i])
    if (to[i] != f) {
      dfs(to[i], id), cmax(mxd[id], mxd[to[i]] + 1);
      if (mxd[to[i]] > mxd[son[id]]) son[id] = to[i];
    }
}
void dfs2(long long id, long long f, long long t) {
  if (son[id])
    dfs2(son[id], id, t);
  else
    buc[++num] = mxd[t];
  for (long long i = hd[id]; i; i = nxt[i])
    if (to[i] != f && to[i] != son[id]) dfs2(to[i], id, to[i]);
}
long long cal(long long r, long long b) { return 1ll * (n - r - b) * (r - b); }
signed main() {
  rd(n), rd(k);
  long long maxn = 0;
  for (long long i = 1, u, v; i < n; i++)
    rd(u), rd(v), add(u, v), add(v, u), siz[u]++, siz[v]++,
        maxn = max(max(maxn, siz[u]), siz[v]);
  dfs(1, 0), dfs2(1, 0, 1);
  if (num <= k)
    for (long long i = 0; i <= k; i++) cmax(ans, 1ll * (n - i) * i);
  else {
    ans = 1e18, sort(buc + 1, buc + num + 1), reverse(buc + 1, buc + num + 1);
    for (long long i = 1; i <= k; i++) tot += buc[i];
    for (long long i = 0; i <= n - tot; i++)
      cmin(ans, 1ll * (n - i - k) * (k - i));
  }
  if (maxn == n - 1 && n - k <= 1)
    printf("%d", n - 1);
  else
    cout << ans << endl;
  return 0;
}

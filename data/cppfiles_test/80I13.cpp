#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e6 + 10;
const int MAXM = +10;
inline int fread(void) {
  char ch = getchar();
  int ret = 0, op = 1;
  while (!isdigit(ch) && ch != '-') ch = getchar();
  if (ch == '-')
    op = -1;
  else
    ret = ch - '0';
  ch = getchar();
  for (; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - '0';
  return ret * op;
}
int a[MAXN], b[MAXN], n, m, c[MAXN];
int nxt[MAXN], pre[MAXN];
struct BIT {
  int t[MAXN];
  inline int lowbit(int x) { return x & (-x); }
  inline void add(int x, int v) {
    for (; x <= n + m; x += lowbit(x)) t[x] += v;
  }
  inline int ask(int x) {
    int ret = 0;
    for (; x; x -= lowbit(x)) ret += t[x];
    return ret;
  }
} T;
inline void init(void) {
  n = fread(), m = fread();
  for (int i = 1; i <= n; ++i) a[i] = fread();
  for (int i = 1; i <= m; ++i) b[i] = fread();
  sort(b + 1, b + m + 1);
  for (int i = 1; i <= n; ++i) nxt[i] = i + 1, pre[i] = i - 1;
  nxt[n] = 0;
}
int p[MAXN], ans[MAXN], tot;
void solve(int l, int r, int lp, int rp) {
  if (l > r || lp > rp) return;
  int mid = (lp + rp) >> 1;
  int delta = 0, pos = l;
  for (int i = l; i <= r; ++i) {
    if (delta > 0) pos = i, delta = 0;
    if (a[i] < b[mid]) ++delta;
    if (a[i] > b[mid]) --delta;
  }
  p[mid] = pos;
  solve(l, p[mid], lp, mid - 1);
  solve(p[mid], r, mid + 1, rp);
}
int res[MAXN];
long long Ans;
void calc(int l, int r) {
  if (l == r) return;
  int mid = (l + r) >> 1;
  calc(l, mid);
  calc(mid + 1, r);
  int lt = l, rt = mid + 1;
  int tmp = l;
  while (lt <= mid && rt <= r) {
    if (ans[lt] <= ans[rt])
      res[tmp++] = ans[lt++];
    else
      Ans += (mid - lt + 1), res[tmp++] = ans[rt++];
  }
  while (lt <= mid) res[tmp++] = ans[lt++];
  while (rt <= r) res[tmp++] = ans[rt++];
  for (int i = l; i <= r; ++i) ans[i] = res[i];
}
inline void work(void) {
  solve(1, n + 1, 1, m);
  p[0] = 1;
  int rt = 0;
  tot = 0;
  for (int i = 1; i <= m; ++i) {
    for (int j = p[i - 1]; j < p[i]; ++j) ans[++tot] = a[j];
    ans[++tot] = b[i];
  }
  Ans = 0;
  calc(1, n + m);
  printf("%lld\n", Ans);
}
int main() {
  int T = fread();
  while (T--) init(), work();
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N = 2e4 + 100;
struct Suffix_Array {
  int n, m, sa[N], rk[N << 1], oldrk[N << 1];
  int id[N], cnt[N], rkid[N], height[N];
  bool cmp(int x, int y, int w) {
    return oldrk[x] == oldrk[y] && oldrk[x + w] == oldrk[y + w];
  }
  void init() {
    for (int i = 0; i <= m + 1; i++)
      height[i] = id[i] = cnt[i] = rkid[i] = sa[i] = 0;
    for (int i = 0; i <= 2 * m + 2; i++) rk[i] = oldrk[i] = 0;
  }
  void solve(char *s) {
    n = strlen(s + 1);
    m = max(n, 256);
    init();
    for (int i = 1; i <= n; i++) ++cnt[rk[i] = s[i]];
    for (int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
    for (int i = n; i > 0; i--) sa[cnt[rk[i]]--] = i;
    for (int w = 1, p; w < n; w <<= 1) {
      p = 0;
      for (int i = n; i > n - w; i--) id[++p] = i;
      for (int i = 1; i <= n; ++i)
        if (sa[i] > w) id[++p] = sa[i] - w;
      memset(cnt, 0, sizeof(int) * (m + 1));
      for (int i = 1; i <= n; i++) ++cnt[rkid[i] = rk[id[i]]];
      for (int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
      for (int i = n; i >= 1; --i) sa[cnt[rkid[i]]--] = id[i];
      swap(rk, oldrk);
      m = 0;
      for (int i = 1; i <= n; i++)
        rk[sa[i]] = (m += (cmp(sa[i], sa[i - 1], w) ^ 1));
    }
    return;
  }
  void GetHeight(char *s) {
    for (int i = 1, k = 0; i <= n; ++i) {
      if (rk[i] == 1)
        k = 0;
      else {
        if (k > 0) k--;
        int j = sa[rk[i] - 1];
        while (i + k <= n && j + k <= n && s[i + k] == s[j + k]) {
          ++k;
        }
      }
      height[rk[i]] = k;
    }
  }
} w;
char s[N];
struct LCP {
  static const int logn = 21;
  static const int maxn = 2000001;
  int f[maxn][logn + 1], Logn[maxn + 1];
  int *height;
  int *rk;
  int n;
  void init(Suffix_Array &o) {
    height = o.height;
    rk = o.rk;
    n = o.n;
  }
  void pre_lcp() {
    Logn[1] = 0;
    Logn[2] = 1;
    for (int i = 3; i < maxn; i++) {
      Logn[i] = Logn[i / 2] + 1;
    }
    for (int j = 1; j <= logn; j++)
      for (int i = 1; i + (1 << j) - 1 <= n; i++) f[i][j] = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++) f[i][0] = height[i];
    for (int j = 1; j <= logn; j++)
      for (int i = 1; i + (1 << j) - 1 <= n; i++)
        f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
  }
  int lcp(int l, int r) {
    if (l == r) return n - l + 1;
    l = rk[l];
    r = rk[r];
    if (l > r) swap(l, r);
    l++;
    int x = Logn[r - l + 1];
    return min(f[l][x], f[r - (1 << x) + 1][x]);
  }
} t;
int f[N], top = 0;
void solve() {
  int n;
  scanf("%d %s", &n, s + 1);
  w.solve(s);
  w.GetHeight(s);
  t.init(w);
  t.pre_lcp();
  int *a = w.rk;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int tmp = 0;
    for (int j = 1; j < i; j++) {
      if (a[i] > a[j]) tmp = max(tmp, f[j] + n - i + 1 - t.lcp(i, j));
    }
    f[i] = max(tmp, n - i + 1);
    ans = max(f[i], ans);
  }
  printf("%d\n", ans);
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}

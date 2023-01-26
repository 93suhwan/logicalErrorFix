#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5010;
int T, n, ans, f[MAXN];
char s[MAXN];
struct SA {
  int sa[MAXN], rk[MAXN * 2], oldrk[MAXN * 2], cnt[MAXN], tmp[MAXN];
  int lcp[MAXN][MAXN], height[MAXN];
  void build(char* s, int n) {
    for (int i = (0); i <= (n * 2 + 5); i++) {
      rk[i] = oldrk[i] = 0;
    }
    int m = max(n, 150);
    for (int i = (0); i <= (m); i++) cnt[i] = 0;
    for (int i = (1); i <= (n); i++) rk[i] = s[i];
    for (int i = (1); i <= (n); i++) cnt[rk[i]]++;
    for (int i = (1); i <= (m); i++) cnt[i] += cnt[i - 1];
    for (int i = (n); i >= (1); i--) sa[cnt[rk[i]]--] = i;
    for (int w = 1; w < n; w <<= 1) {
      int p = 0;
      for (int i = (n - w + 1); i <= (n); i++) tmp[++p] = i;
      for (int i = (1); i <= (n); i++)
        if (sa[i] > w) tmp[++p] = sa[i] - w;
      for (int i = (0); i <= (m); i++) cnt[i] = 0;
      for (int i = (1); i <= (n); i++) cnt[rk[tmp[i]]]++;
      for (int i = (1); i <= (m); i++) cnt[i] += cnt[i - 1];
      for (int i = (n); i >= (1); i--) sa[cnt[rk[tmp[i]]]--] = tmp[i];
      for (int i = (1); i <= (n); i++) oldrk[i] = rk[i];
      rk[sa[1]] = 1;
      for (int i = (2); i <= (n); i++) {
        rk[sa[i]] = rk[sa[i - 1]];
        if (oldrk[sa[i]] != oldrk[sa[i - 1]] ||
            oldrk[sa[i] + w] != oldrk[sa[i - 1] + w])
          rk[sa[i]]++;
      }
    }
    int j = 0;
    for (int i = (1); i <= (n); i++) {
      if (j) j--;
      while (s[i + j] == s[sa[rk[i] - 1] + j]) j++;
      height[rk[i]] = j;
    }
    for (int i = (1); i <= (n); i++) {
      lcp[i][i] = (n - sa[i] + 1);
      for (int j = (i + 1); j <= (n); j++) {
        lcp[i][j] = min(lcp[i][j - 1], height[j]);
      }
    }
  }
  int query(int L, int R) {
    L = rk[L];
    R = rk[R];
    if (L > R) swap(L, R);
    return lcp[L][R];
  }
} sa;
void solve() {
  scanf("%d%s", &n, s + 1);
  sa.build(s, n);
  ans = 0;
  for (int i = (1); i <= (n); i++) {
    f[i] = n - i + 1;
    for (int j = (1); j <= (i - 1); j++) {
      int len = sa.query(i, j);
      if (i + len - 1 == n || s[i + len] < s[j + len]) continue;
      f[i] = max(f[i], f[j] + (n - i + 1 - len));
    }
    ans = max(ans, f[i]);
  }
  printf("%d\n", ans);
}
int main() {
  scanf("%d", &T);
  while (T--) {
    solve();
  }
  return 0;
}

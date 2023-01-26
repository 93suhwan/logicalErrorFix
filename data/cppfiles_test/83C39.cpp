#include <bits/stdc++.h>
using namespace std;
const int NR = 5005;
void Min(int& x, int y) { x = min(x, y); }
void Max(int& x, int y) { x = max(x, y); }
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
int n, m;
char s[NR << 1];
int sa[NR << 1], id[NR << 1];
int rk[NR << 1], lark[NR << 1];
int cnt[NR];
int h[NR << 1];
int dp[NR << 1];
int mn[NR][NR];
void work() {
  memset(s, 0, sizeof(s));
  memset(sa, 0, sizeof(sa));
  memset(rk, 0, sizeof(rk));
  n = read(), scanf("%s", s + 1);
  m = max(n, 300);
  memset(cnt, 0, sizeof(cnt));
  for (int i = 1; i <= n; i++) cnt[rk[i] = s[i]]++;
  for (int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
  for (int i = n; i >= 1; i--) sa[cnt[rk[i]]--] = i;
  for (int w = 1; w < n; w <<= 1) {
    memset(cnt, 0, sizeof(cnt));
    int p = 0;
    for (int i = n - w + 1; i <= n; i++) id[++p] = i;
    for (int i = 1; i <= n; i++)
      if (sa[i] > w) id[++p] = sa[i] - w;
    for (int i = 1; i <= n; i++) cnt[rk[id[i]]]++;
    for (int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
    for (int i = n; i >= 1; i--) sa[cnt[rk[id[i]]]--] = id[i];
    memcpy(lark, rk, sizeof(lark));
    rk[sa[1]] = m = 1;
    for (int i = 2; i <= n; i++) {
      if (lark[sa[i]] == lark[sa[i - 1]] &&
          lark[sa[i] + w] == lark[sa[i - 1] + w])
        rk[sa[i]] = m;
      else
        rk[sa[i]] = ++m;
    }
  }
  memset(h, 0, sizeof(h));
  int lcp = 0;
  for (int i = 1; i <= n; i++) {
    if (lcp) lcp--;
    while (s[i + lcp] == s[sa[rk[i] - 1] + lcp]) lcp++;
    h[rk[i]] = lcp;
  }
  for (int i = 1; i <= n; i++) {
    mn[i][i] = h[i];
    for (int j = i + 1; j <= n; j++) mn[i][j] = min(mn[i][j - 1], h[j]);
  }
  int ans = 0;
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i <= n; i++) {
    int len = dp[i] = n - i + 1;
    for (int j = 1; j < i; j++) {
      if (rk[i] < rk[j]) continue;
      dp[i] = max(dp[i], dp[j] + len - mn[rk[j] + 1][rk[i]]);
    }
    ans = max(ans, dp[i]);
  }
  printf("%d\n", ans);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) mn[i][j] = 0;
}
int main() {
  int T = read();
  while (T--) work();
  return 0;
}

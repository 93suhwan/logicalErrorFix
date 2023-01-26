#include <bits/stdc++.h>
using namespace std;
int read() {
  int w = 0, flg = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') {
      flg = -1;
    }
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0') {
    w = w * 10 + ch - '0', ch = getchar();
  }
  return w * flg;
}
int T;
int n, m = 'z' + 10, num, sa[5010], c[5010], x[5010], y[5010], dp[5010],
       del[5010][5010], id[5010];
char s[5010];
void suffix_sort() {
  for (int i = (1); i <= (n); i++) x[i] = s[i], c[x[i]]++;
  for (int i = (2); i <= (m); i++) c[i] += c[i - 1];
  for (int i = (n); i >= (1); i--) sa[c[x[i]]--] = i;
  for (int k = 1; k <= n; k <<= 1) {
    num = 0;
    for (int i = (n - k + 1); i <= (n); i++) y[++num] = i;
    for (int i = (1); i <= (n); i++)
      if (sa[i] > k) y[++num] = sa[i] - k;
    for (int i = (1); i <= (m); i++) c[i] = 0;
    for (int i = (1); i <= (n); i++) c[x[i]]++;
    for (int i = (2); i <= (m); i++) c[i] += c[i - 1];
    for (int i = (n); i >= (1); i--) sa[c[x[y[i]]]--] = y[i];
    for (int i = (1); i <= (n); i++) y[i] = x[i];
    num = 1, x[sa[1]] = 1;
    for (int i = (2); i <= (n); i++) {
      if (y[sa[i]] == y[sa[i - 1]] && y[sa[i] + k] == y[sa[i - 1] + k])
        x[sa[i]] = num;
      else
        x[sa[i]] = ++num;
    }
    if (num == n) break;
    m = num;
  }
}
int ans;
void solve() {
  n = read();
  scanf("%s", s + 1);
  suffix_sort();
  for (int i = (1); i <= (n); i++) id[sa[i]] = i;
  for (int i = (n); i >= (1); i--)
    for (int j = (n); j >= (1); j--)
      if (s[i] == s[j]) del[i][j] = del[i + 1][j + 1] + 1;
  for (int i = (1); i <= (n); i++) {
    dp[i] = n - i + 1;
    for (int j = (1); j <= (i - 1); j++) {
      if (id[i] < id[j]) continue;
      dp[i] = max(dp[i], dp[j] + n - i + 1 - del[i][j]);
    }
    ans = max(ans, dp[i]);
  }
  printf("%d\n", ans);
  for (int i = (0); i <= (5000); i++)
    sa[i] = c[i] = x[i] = y[i] = dp[i] = id[i] = s[i] = 0;
  for (int i = (0); i <= (n + 1); i++)
    for (int j = (0); j <= (n + 1); j++) del[i][j] = 0;
  num = 0, ans = 0, m = 'z' + 10;
}
int main() {
  T = read();
  while (T--) solve();
  return 0;
}

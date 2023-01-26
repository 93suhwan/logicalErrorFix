#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e3 + 5;
int readint() {
  int x = 0, f = 1;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    (s = getchar());
  }
  while (s >= '0' && s <= '9') {
    x = (x << 3) + (x << 1) + (s ^ 48);
    (s = getchar());
  }
  return x * f;
}
char s[maxn];
int cnt[maxn], maxsize;
int sa[maxn], rk[maxn];
int x[maxn << 1], y[maxn << 1];
int lcp[maxn][maxn];
int height[maxn];
int dp[maxn];
void get_sa(int n) {
  int maxsize = 150;
  for (int i = 1; i <= maxsize; i++) cnt[i] = 0;
  for (int i = 1; i <= n; i++)
    x[i] = x[i << 1] = 0, y[i] = y[i << 1] = 0, rk[i] = 0, height[i] = 0,
    sa[i] = 0;
  for (int i = 1; i <= n; i++) {
    x[i] = s[i];
    cnt[x[i]]++;
  }
  for (int i = 2; i <= maxsize; i++) cnt[i] += cnt[i - 1];
  for (int i = n; i >= 1; i--) sa[cnt[x[i]]--] = i;
  for (int k = 1; k <= n; k <<= 1) {
    int num = 0;
    for (int i = n - k + 1; i <= n; i++) y[++num] = i;
    for (int i = 1; i <= n; i++)
      if (sa[i] > k) y[++num] = sa[i] - k;
    for (int i = 1; i <= maxsize; i++) cnt[i] = 0;
    for (int i = 1; i <= n; i++) ++cnt[x[i]];
    for (int i = 2; i <= maxsize; i++) cnt[i] += cnt[i - 1];
    for (int i = n; i >= 1; i--) sa[cnt[x[y[i]]]--] = y[i], y[i] = 0;
    swap(x, y);
    x[sa[1]] = 1;
    num = 1;
    for (int i = 2; i <= n; i++)
      x[sa[i]] = (y[sa[i]] == y[sa[i - 1]] && y[sa[i] + k] == y[sa[i - 1] + k])
                     ? num
                     : ++num;
    if (num == n) break;
    maxsize = num;
  }
}
void getheight(int n) {
  for (int i = 1; i <= n; i++) rk[sa[i]] = i;
  int k = 0;
  for (int i = 1; i <= n; i++) {
    if (rk[i] == 1) continue;
    if (k) k--;
    int j = sa[rk[i] - 1];
    while (i + k <= n && j + k <= n && s[j + k] == s[i + k]) k++;
    height[rk[i]] = k;
  }
}
void getlcp(int n) {
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) lcp[i][j] = 0;
  for (int i = 1; i <= n; i++) {
    lcp[i][i] = n - sa[i] + 1;
    for (int j = i + 1; j <= n; j++) lcp[i][j] = min(lcp[i][j - 1], height[j]);
  }
}
int query(int i, int j) {
  int l = rk[i], r = rk[j];
  if (l > r) swap(l, r);
  return lcp[l][r];
}
int main() {
  int t = readint();
  while (t--) {
    int n = readint();
    scanf("%s", s + 1);
    get_sa(n);
    getheight(n);
    getlcp(n);
    for (int i = 1; i <= n; i++) dp[i] = 0;
    dp[1] = n;
    for (int i = 2; i <= n; i++) {
      dp[i] = n - i + 1;
      for (int j = 1; j <= i - 1; j++) {
        int len = query(i, j);
        if (rk[j] > rk[i] || len == n - i + 1) continue;
        dp[i] = max(dp[i], dp[j] + n - i + 1 - len);
      }
    }
    int maxx = 0;
    for (int i = 1; i <= n; i++) {
      maxx = max(dp[i], maxx);
    }
    printf("%d\n", maxx);
  }
  return 0;
}

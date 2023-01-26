#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0;
  char c = getchar();
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
  return x;
}
const int maxn = 5010;
int n, m;
char s[maxn];
int c[maxn], x[maxn], y[maxn], sa[maxn], rk[maxn], height[maxn];
void get_sa() {
  for (int i = 1; i <= n; i++) c[x[i] = s[i]]++;
  for (int i = 2; i <= m; i++) c[i] += c[i - 1];
  for (int i = n; i; i--) sa[c[x[i]]--] = i;
  for (int k = 1; k <= n; k <<= 1) {
    int num = 0;
    for (int i = n - k + 1; i <= n; i++) y[++num] = i;
    for (int i = 1; i <= n; i++)
      if (sa[i] > k) y[++num] = sa[i] - k;
    for (int i = 1; i <= m; i++) c[i] = 0;
    for (int i = 1; i <= n; i++) c[x[i]]++;
    for (int i = 2; i <= m; i++) c[i] += c[i - 1];
    for (int i = n; i; i--) sa[c[x[y[i]]]--] = y[i], y[i] = 0;
    swap(x, y);
    x[sa[1]] = 1, num = 1;
    for (int i = 2; i <= n; i++)
      x[sa[i]] = (y[sa[i]] == y[sa[i - 1]] && y[sa[i] + k] == y[sa[i - 1] + k])
                     ? num
                     : ++num;
    if (num == n) break;
    m = num;
  }
}
void get_height() {
  for (int i = 1; i <= n; i++) rk[sa[i]] = i;
  for (int i = 1, k = 0; i <= n; i++) {
    if (rk[i] == 1) continue;
    if (k) k--;
    int j = sa[rk[i] - 1];
    while (i + k <= n && j + k <= n && s[i + k] == s[j + k]) k++;
    height[rk[i]] = k;
  }
}
int f[maxn][20];
void Init_st() {
  for (int i = 1; i <= n; i++) f[i][0] = height[i];
  int t = log(n) / log(2) + 1;
  for (int j = 1; j < t; j++)
    for (int i = 1; i <= n - (1 << j) + 1; i++)
      f[i][j] = min(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);
}
inline int query_st(int l, int r) {
  int k = log(r - l + 1) / log(2);
  return min(f[l][k], f[r - (1 << k) + 1][k]);
}
inline int lcp(int x, int y) {
  if (!x || !y) return 0;
  if (x == y) return n - x + 1;
  if (rk[x] > rk[y]) swap(x, y);
  return query_st(rk[x] + 1, rk[y]);
}
int dp[maxn];
int main() {
  int T = read();
  while (T--) {
    memset(y, 0, sizeof(y));
    memset(x, 0, sizeof(x));
    memset(c, 0, sizeof(c));
    n = read();
    m = 122;
    scanf("%s", s + 1);
    get_sa();
    get_height();
    Init_st();
    for (int i = 1; i <= n; i++) dp[i] = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < i; j++) {
        if (rk[j] > rk[i]) continue;
        int t = lcp(j, i);
        dp[i] = max(dp[i], dp[j] + n - i - t + 1);
      }
      ans = max(ans, dp[i]);
    }
    printf("%d\n", ans);
  }
  return 0;
}

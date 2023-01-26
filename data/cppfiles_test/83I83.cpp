#include <bits/stdc++.h>
using namespace std;
char s[10010];
namespace Sa {
int n, m = 26;
int H[10010], rk[10010], rk2[10010], sa[10010], sa2[10010];
int gg[10010];
void sort() {
  memset(gg, 0, sizeof(gg));
  for (int i = 1; i <= n; i++) ++gg[rk[i]];
  for (int i = 1; i <= m; i++) gg[i] += gg[i - 1];
  for (int i = n; i >= 1; i--) sa[gg[rk[sa2[i]]]--] = sa2[i];
}
void HH() {
  memset(H, 0, sizeof(H));
  int k = 0;
  for (int i = 1; i <= n; i++) {
    if (rk[i] == 1) {
      k = H[1] = 0;
      continue;
    }
    if (k) --k;
    int j = sa[rk[i] - 1];
    while (i + k <= n && j + k <= n && s[i + k] == s[j + k]) ++k;
    H[rk[i]] = k;
  }
}
void SA() {
  for (int i = 1; i <= n; i++) {
    rk[i] = s[i] - 'a' + 1;
    sa2[i] = i;
  }
  sort();
  for (int d = 1; d < n; d <<= 1) {
    int p = 0;
    for (int i = n - d + 1; i <= n; i++) sa2[++p] = i;
    for (int i = 1; i <= n; i++)
      if (sa[i] > d) sa2[++p] = sa[i] - d;
    sort();
    rk2[sa[1]] = p = 1;
    for (int i = 2; i <= n; i++) {
      if (rk[sa[i]] != rk[sa[i - 1]] || rk[sa[i] + d] != rk[sa[i - 1] + d]) ++p;
      rk2[sa[i]] = p;
    }
    for (int i = 1; i <= n; i++) rk[i] = rk2[i];
    m = p;
    if (m == n) break;
  }
  HH();
}
}  // namespace Sa
using namespace Sa;
int lg[10010], mn[10010][30];
int Min(int l, int r) {
  int len = (r - l + 1);
  len = lg[len];
  return min(mn[l][len], mn[r - (1 << len) + 1][len]);
}
int lcp(int x, int y) {
  x = rk[x];
  y = rk[y];
  if (x > y) swap(x, y);
  return Min(x + 1, y);
}
int dp[10010];
signed main() {
  int T;
  scanf("%d", &T);
  lg[0] = -1;
  for (int i = 1; i <= 5000; i++) lg[i] = lg[i >> 1] + 1;
  int Now = 0;
  while (T--) {
    ++Now;
    scanf("%d", &n);
    m = 26;
    scanf(" %s", s + 1);
    SA();
    for (int i = 1; i <= n; i++) mn[i][0] = H[i];
    for (int L = 1; L <= lg[n]; L++)
      for (int i = 1; i <= n; i++)
        mn[i][L] = min(mn[i][L - 1], mn[i + (1 << (L - 1))][L - 1]);
    dp[1] = n;
    dp[0] = 0;
    int mx = n;
    for (int i = 2; i <= n; i++) {
      dp[i] = n - i + 1;
      for (int j = 1; j < i; j++)
        if (rk[i] > rk[j]) {
          dp[i] = max(dp[i], dp[j] + n - i + 1 - lcp(i, j));
        }
      mx = max(mx, dp[i]);
    }
    if (Now == 41) {
      printf("%d %s ", n, s + 1);
    }
    printf("%d\n", mx);
  }
}

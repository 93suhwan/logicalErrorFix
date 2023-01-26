#include <bits/stdc++.h>
using namespace std;
const int MAXN = 23, MAXM = 2e4 + 10, LIM = (1 << MAXN), mod = 998244353;
int n, f[1 << MAXN], g[1 << MAXN], F[1 << MAXN];
long long ans;
int pcnt[1 << MAXN], psum[1 << MAXN], tag[1 << MAXN];
char s[MAXN][MAXM];
int cnt[MAXN][26];
int main() {
  for (int i = (0); i <= (22); i++) tag[1 << i] = i;
  for (int i = (1); i <= ((1 << 23) - 1); i++) {
    pcnt[i] = pcnt[i - (i & -i)] + 1;
    psum[i] = psum[i - (i & -i)] + tag[(i & -i)] + 1;
  }
  scanf("%d", &n);
  for (int i = (0); i <= (n - 1); i++) {
    scanf("%s", s[i] + 1);
    int len = strlen(s[i] + 1);
    for (int j = (1); j <= (len); j++) {
      cnt[i][s[i][j] - 'a']++;
    }
  }
  for (int i = (1); i <= ((1 << n) - 1); i++) f[i] = 1;
  for (int i = (0); i <= (25); i++) {
    g[0] = 1e9;
    for (int j = (1); j <= ((1 << n) - 1); j++) {
      g[j] = min(g[j ^ (j & -j)], cnt[tag[(j & -j)]][i]);
      f[j] = 1LL * f[j] * (g[j] + 1) % mod;
    }
  }
  for (int i = (1); i <= ((1 << n) - 1); i++) {
    if ((pcnt[i] & 1))
      F[i] = f[i];
    else
      F[i] = mod - f[i];
  }
  for (int i = (0); i <= (22); i++) {
    for (int j = (1); j <= ((1 << n) - 1); j++) {
      if (j >> i & 1) {
        F[j] = (F[j] + F[j ^ (1 << i)]) % mod;
      }
    }
  }
  for (int j = (1); j <= ((1 << n) - 1); j++) {
    ans ^= (1LL * F[j] * pcnt[j] * psum[j]);
  }
  printf("%lld", ans);
  return 0;
}

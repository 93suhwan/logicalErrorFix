#include <bits/stdc++.h>
using namespace std;
const int N = 24, M = 1 << 24, mod = 998244353;
int n;
int cnt[N][27], c[27];
long long f[M][2];
map<int, int> S;
int main() {
  scanf("%d", &n);
  for (int i = 0, j = 1; i < n; i++) {
    S[j] = i;
    j *= 2;
  }
  string str;
  for (int i = 0; i < n; i++) {
    cin >> str;
    for (int j = 0; str[j]; j++) cnt[i][str[j] - 'a']++;
  }
  for (int i = 1; i < 1 << n; i++) {
    int k = 0;
    memset(c, 0x3f, sizeof c);
    for (int j = 0; j < n; j++)
      if (i >> j & 1) {
        k++;
        for (int u = 0; u < 26; u++) c[u] = min(c[u], cnt[j][u]);
      }
    long long res = 1;
    for (int j = 0; j < 26; j++) res = res * (c[j] + 1) % mod;
    if (k & 1)
      f[i][1] = res;
    else
      f[i][0] = res;
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 1 << n; j++)
      if (j >> i & 1)
        f[j][1] = (f[j][1] + f[j - (1 << i)][1]) % mod,
        f[j][0] = (f[j][0] + f[j - (1 << i)][0]) % mod;
  long long res = 0;
  for (int i = (1 << n) - 1; i >= 1; i--) {
    f[i][1] = (f[i][1] - f[i][0] + 2 * mod) % mod;
    int k = 0, s = 0;
    for (int j = 0; j < n; j++)
      if (i >> j & 1) k++, s += j;
    s += k;
    res ^= f[i][1] * s * k;
  }
  printf("%lld\n", res);
  return 0;
}

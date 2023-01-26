#include <bits/stdc++.h>
using namespace std;
const int N = 24, M = 1 << 24, mod = 998244353;
int n;
int cnt[N][27];
long long f[M];
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
    int k = 0, t = i;
    while (t) k++, t -= t & -t;
    if (k == 1) {
      long long res = 1, j = S[i];
      for (int u = 0; u < 26; u++) res = res * (cnt[j][u] + 1) % mod;
      f[i] = res;
    } else if (k == 2) {
      int t = i;
      int c1 = S[t & -t], c2 = S[t - (t & -t)];
      f[i] = (f[1 << c1] + f[1 << c2]) % mod;
      long long res = 1;
      for (int j = 0; j < 26; j++)
        res = res * (min(cnt[c1][j], cnt[c2][j]) + 1) % mod;
      f[i] = (f[i] - res + mod) % mod;
    } else {
      int t = i - (i & -i);
      int c1 = S[i & -i], c2 = S[t & -t];
      long long res = 1;
      for (int j = 0; j < 26; j++)
        res = res * (min(cnt[c1][j], cnt[c2][j]) + 1) % mod;
      long long x =
          f[1 << c1] + f[i ^ (1 << c1) ^ (1 << c2)] - f[i ^ (1 << c2)];
      long long y =
          f[1 << c1] + f[i ^ (1 << c1) ^ (1 << c2)] - f[i ^ (1 << c1)];
      long long z = f[1 << c1] + f[1 << c2] - res;
      f[i] = (f[i ^ (1 << c1) ^ (1 << c2)] - x - y + z + res) % mod;
    }
  }
  long long res = 0;
  for (int i = 1; i < 1 << n; i++) {
    f[i] = (f[i] + mod) % mod;
    int k = 0, s = 0;
    for (int j = 0; j < n; j++)
      if (i >> j & 1) k++, s += j;
    s += k;
    res ^= 1ll * k * s * f[i];
  }
  printf("%lld\n", res);
  return 0;
}

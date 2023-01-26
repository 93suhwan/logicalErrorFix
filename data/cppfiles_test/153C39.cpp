#include <bits/stdc++.h>
using namespace std;
int n;
char s[20010];
int cnt[25][30];
long long f[1 << 23];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", s);
    for (int j = 0; s[j]; j++) cnt[i][s[j] - 'a']++;
  }
  for (int i = 1; i < (1 << n); i++) {
    f[i] = 1;
    for (int j = 0; j < 26; j++) {
      int mn = 1e9;
      for (int k = 0; k < n; k++)
        if (i >> k & 1) mn = min(mn, cnt[k][j]);
      f[i] = f[i] * (mn + 1) % 998244353;
    }
    f[i] = -f[i];
    for (int j = 0; j < n; j++)
      if (i >> j & 1) f[i] = -f[i];
    f[i] = (f[i] + 998244353) % 998244353;
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < (1 << n); j++)
      if (j >> i & 1) f[j] = (f[j] + f[j ^ (1 << i)]) % 998244353;
  long long ans = 0;
  for (int i = 1; i < (1 << n); i++) {
    int x = 0, y = 0;
    for (int j = 0; j < n; j++)
      if (i >> j & 1) x++, y += j + 1;
    ans ^= f[i] * x * y;
  }
  printf("%lld\n", ans);
  return 0;
}

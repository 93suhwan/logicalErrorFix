#include <bits/stdc++.h>
using namespace std;
int n, a[24][26], c[26];
char str[200011];
long long f[10000001][2];
const int p = 998244353;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%s", str + 1);
    int m = strlen(str + 1);
    for (int j = 1; j <= m; j++) ++a[i][str[j] - 'a'];
  }
  for (int i = 1; i < 1 << n; i++) {
    memset(c, 127, sizeof(c));
    int cnt = 0;
    for (int j = 0; j < n; j++)
      if (i & (1 << j)) {
        ++cnt;
        for (int k = 0; k < 26; k++) c[k] = min(c[k], a[j + 1][k]);
      }
    long long res = 1;
    for (int k = 0; k < 26; k++) res *= (c[k] + 1), res %= p;
    if (cnt & 1)
      f[i][1] = res;
    else
      f[i][0] = res;
  }
  int tot = 1 << n;
  for (int j = 0; j < tot; j++)
    for (int i = 0; i < n; i++)
      if (j & (1 << i))
        f[j][0] += f[j - (1 << i)][0], f[j][0] %= p,
            f[j][1] += f[j - (1 << i)][1], f[j][1] %= p;
  long long ans = 0;
  for (int i = 1; i < 1 << n; i++) {
    int cnt = 0, num = 0;
    for (int j = 0; j < n; j++)
      if (i & (1 << j)) {
        ++cnt;
        num += j + 1;
      }
    f[i][1] -= f[i][0];
    if (f[i][1] < 0) f[i][1] += p;
    ans ^= cnt * num * f[i][1];
  }
  printf("%lld\n", ans);
}

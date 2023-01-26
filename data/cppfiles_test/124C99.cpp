#include <bits/stdc++.h>
using namespace std;
const int maxn = 2005;
const int mod = 1e9 + 7;
int T, n, ans;
int pre[maxn][maxn * 2], suf[maxn][maxn * 2];
char s[maxn], t[maxn];
void add(int &a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d %s %s", &n, s + 1, t + 1);
    for (int i = 0; i <= n + 1; i++)
      for (int j = -n; j <= n; j++) pre[i][j + n] = suf[i][j + n] = 0;
    pre[0][0 + n] = 1;
    for (int i = 0; i < n; i++)
      for (int j = -n; j <= n; j++) {
        int cur = pre[i][j + n];
        if (!cur) continue;
        for (int fs = 0; fs < 2; fs++)
          if (s[i + 1] == '?' || s[i + 1] == '0' + fs)
            for (int ft = 0; ft < 2; ft++)
              if (t[i + 1] == '?' || t[i + 1] == '0' + ft)
                add(pre[i + 1][j + ((i + 1) & 1 ? fs - ft : ft - fs) + n], cur);
      }
    suf[n + 1][0 + n] = 1;
    for (int i = n + 1; i >= 2; i--)
      for (int j = -n; j <= n; j++) {
        int cur = suf[i][j + n];
        if (!cur) continue;
        for (int fs = 0; fs < 2; fs++)
          if (s[i - 1] == '?' || s[i - 1] == '0' + fs)
            for (int ft = 0; ft < 2; ft++)
              if (t[i - 1] == '?' || t[i - 1] == '0' + ft)
                add(suf[i - 1][j + ((i - 1) & 1 ? fs - ft : ft - fs) + n], cur);
      }
    ans = 0;
    for (int i = 0; i <= n; i++)
      for (int j = -n; j <= n; j++)
        if (pre[i][j + n] && suf[i + 1][-j + n])
          ans =
              (ans + 1LL * pre[i][j + n] * suf[i + 1][-j + n] % mod * abs(j)) %
              mod;
    printf("%d\n", ans);
  }
  return 0;
}

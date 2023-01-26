#include <bits/stdc++.h>
using namespace std;
char st[20005];
int w[26][26], f[(1 << 23)], in[(1 << 23)][26];
void sol(int, int);
int main() {
  long long ml, ans = 0;
  int i, j, k, s, n, cnt, sm;
  scanf("%d", &n);
  for (i = 1; i <= n; ++i) {
    scanf("%s", st + 1);
    k = strlen(st + 1);
    for (j = 1; j <= k; ++j) ++w[i][st[j] - 'a'];
  }
  for (i = 0; i < 26; ++i) in[0][i] = 0x3f3f3f3f;
  for (s = 1; s < (1 << n); ++s) {
    ml = 1;
    cnt = 0;
    for (i = n; i; --i)
      if (s & (1 << i - 1)) {
        k = i;
        ++cnt;
      }
    for (i = 0; i < 26; ++i) {
      in[s][i] = min(in[s ^ (1 << k - 1)][i], w[k][i]);
      (ml *= in[s][i] + 1) %= 998244353;
    }
    f[s] = ml;
    if (!(cnt & 1)) f[s] = -ml;
  }
  sol(n, 0);
  for (s = 1; s < (1 << n); ++s) {
    cnt = sm = 0;
    for (i = 1; i <= n; ++i)
      if (s & (1 << i - 1)) {
        ++cnt;
        sm += i;
      }
    ans ^= 1ll * f[s] * cnt * sm;
  }
  printf("%lld\n", ans);
  return 0;
}
void sol(int k, int s) {
  if (!k) return;
  sol(k - 1, s);
  sol(k - 1, s | (1 << k - 1));
  for (int i = 0; i < (1 << k - 1); ++i)
    (f[s | (1 << k - 1) | i] += f[s | i]) %= 998244353;
}

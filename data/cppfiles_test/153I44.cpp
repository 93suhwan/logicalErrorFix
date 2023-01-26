#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353, maxn = 23;
inline int Add(int x, int y) { return (x += y) >= mod ? x - mod : x; }
inline int Mul(int x, int y) { return 1ll * x * y % mod; }
int n, cnt[maxn][26], f[1 << maxn], minx[26];
char s[maxn];
long long ans;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%s", s);
    int len = strlen(s);
    for (int j = 0; j < len; ++j) ++cnt[i][s[j] - 'a'];
  }
  for (int s = 1; s < 1 << n; ++s) {
    for (int j = 0; j < 26; ++j) minx[j] = 1e9;
    for (int i = 0; i < n; ++i)
      if (s >> i & 1)
        for (int j = 0; j < 26; ++j) minx[j] = min(minx[j], cnt[i][j]);
    f[s] = __builtin_popcount(s) & 1 ? 1 : mod - 1;
    for (int j = 0; j < 26; ++j) f[s] = Mul(f[s], minx[j] + 1);
  }
  for (int i = 0; i < n; ++i)
    for (int s = 0; s < (1 << n); ++s)
      if (s >> i & 1) f[s] = Add(f[s], f[s ^ (1 << i)]);
  for (int s = 1; s < (1 << n); ++s) {
    int res = 0;
    for (int i = 0; i < n; ++i)
      if (s >> i & 1) res += i + 1;
    ans ^= 1ll * res * f[s] * __builtin_popcount(s);
  }
  printf("%lld\n", ans);
}

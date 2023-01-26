#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 2005 * 60;
const long long INF = 0x3f3f3f3f;
const long long MAXC = 7;
const long long MOD = 1e9 + 7;
long long inline read() {
  long long x = 0, f = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') f ^= (ch == '-'), ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + (ch ^ 48), ch = getchar();
  return f ? -x : x;
}
long long inline qpow(long long x, long long y) {
  long long ret = 1;
  while (y) {
    if (y & 1) ret = ret * x % MOD;
    y >>= 1;
    x = x * x % MOD;
  }
  return ret;
}
long long n, m, cnt = 0, sta[MAXN], stop = 0, col[MAXN];
map<long long, long long> mp;
struct dp_val {
  long long f[MAXC];
};
dp_val dfs(long long u, long long dep) {
  long long nullans = qpow(4, (1ll << (n - dep + 1)) - 2);
  if (!mp[u])
    return dp_val{{0, nullans, nullans, nullans, nullans, nullans, nullans}};
  dp_val lans, rans, ans;
  if (dep < n) {
    lans = dfs(u << 1, dep + 1);
    rans = dfs(u << 1 | 1, dep + 1);
    ans = {{0, 0, 0, 0, 0, 0, 0}};
    for (long long i = 1; i <= 6; ++i) {
      for (long long j = 1; j <= 6; ++j)
        for (long long k = 1; k <= 6; ++k)
          if (i != j && i + j != 7 && i != k && i + k != 7)
            ans.f[i] = (ans.f[i] + lans.f[j] * rans.f[k]) % MOD;
    }
  } else
    ans = {{0, 1, 1, 1, 1, 1, 1}};
  if (col[mp[u]])
    for (long long i = 1; i <= 6; ++i)
      if (i != col[mp[u]]) ans.f[i] = 0;
  return ans;
}
signed main() {
  n = read();
  m = read();
  for (long long i = 1; i <= m; ++i) {
    char str[MAXN];
    long long u = read(), w;
    scanf("%s", str);
    if (!strcmp(str, "white")) w = 1;
    if (!strcmp(str, "yellow")) w = 6;
    if (!strcmp(str, "green")) w = 3;
    if (!strcmp(str, "blue")) w = 4;
    if (!strcmp(str, "red")) w = 5;
    if (!strcmp(str, "orange")) w = 2;
    if (!mp[u]) mp[u] = ++cnt, sta[++stop] = u;
    col[mp[u]] = w;
    while (u != 1) {
      u >>= 1;
      if (!mp[u]) mp[u] = ++cnt, sta[++stop] = u;
    }
  }
  dp_val ans = dfs(1, 1);
  long long final_ans = 0;
  for (long long i = 1; i <= 6; ++i) final_ans = (final_ans + ans.f[i]) % MOD;
  printf("%lld\n", final_ans);
  return 0;
}

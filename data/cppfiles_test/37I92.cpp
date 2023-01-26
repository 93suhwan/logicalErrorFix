#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x) {
  T f = 1;
  x = 0;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s >= '0' && s <= '9') {
    x = (x << 3) + (x << 1) + (s ^ '0');
    s = getchar();
  }
  x *= f;
}
template <typename T>
void write(T x, char s = '\n') {
  if (!x) {
    putchar('0');
    putchar(s);
    return;
  }
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  T t = 0, tmp[25] = {};
  while (x) tmp[t++] = x % 10, x /= 10;
  while (t-- > 0) putchar(tmp[t] + '0');
  putchar(s);
}
const int MAXN = 1e5 + 5;
const int mod = 998244353;
long long ans[MAXN], dp[MAXN][2], fac[MAXN], finv[MAXN], deg[MAXN];
int head[MAXN], to[MAXN << 1], nxt[MAXN << 1], cnt, n;
void add(int u, int v) {
  nxt[++cnt] = head[u];
  head[u] = cnt;
  to[cnt] = v;
}
long long C(long long n, long long m) {
  if (m > n || n < 0) return 0;
  return fac[n] * finv[n - m] % mod * finv[m] % mod;
}
long long qpow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
long long tmp[MAXN];
void dfs(int x, int fa, long long k) {
  dp[x][0] = dp[x][1] = 0;
  for (int i = head[x]; i; i = nxt[i]) {
    int v = to[i];
    if (v == fa) continue;
    dfs(v, x, k);
  }
  if (k * k > n - 1) {
    if (deg[x] < k) {
      dp[x][1] = 0;
      dp[x][0] = 1;
      for (int i = head[x]; i; i = nxt[i]) {
        int v = to[i];
        if (v == fa) continue;
        dp[x][0] *= dp[v][1];
      }
    } else {
      long long zer = 0, one = 0, bot = 0, nei = 0;
      for (int i = head[x]; i; i = nxt[i]) {
        int v = to[i];
        if (v == fa) continue;
        if (dp[v][0] && dp[v][1])
          bot++;
        else if (dp[v][1])
          one++;
        else if (dp[v][0])
          zer++;
        else
          nei++;
      }
      if (nei)
        dp[x][0] = dp[x][1] = 0;
      else {
        if (zer <= k && zer + bot >= k)
          dp[x][0] = 1;
        else
          dp[x][0] = 0;
        if (zer <= k - 1 && zer + bot >= k - 1)
          dp[x][1] = 1;
        else
          dp[x][1] = 0;
      }
    }
  } else {
    for (int i = 0; i < k; ++i) tmp[i] = 0;
    tmp[0] = 1;
    for (int i = head[x]; i; i = nxt[i]) {
      int v = to[i];
      if (v == fa) continue;
      long long las = tmp[k - 1];
      for (int j = k - 1; j > 0; --j)
        tmp[j] = (tmp[j] * dp[v][1] + tmp[j - 1] * dp[v][0]) % mod;
      tmp[0] = (tmp[0] * dp[v][1] + las * dp[v][0]) % mod;
    }
    dp[x][0] = tmp[0], dp[x][1] = tmp[k - 1];
  }
}
long long calc(long long x) {
  dfs(1, 0, x);
  return dp[1][0];
}
int main() {
  int T;
  read(T);
  int N = 1e5;
  fac[0] = finv[0] = 1;
  for (int i = 1; i <= N; ++i) fac[i] = fac[i - 1] * i % mod;
  finv[N] = qpow(fac[N], mod - 2);
  for (int i = N - 1; i >= 1; --i) finv[i] = finv[i + 1] * (i + 1) % mod;
  while (T-- > 0) {
    read(n);
    for (int i = 1; i < n; ++i) {
      int u, v;
      read(u), read(v);
      add(u, v), add(v, u);
      deg[u]++, deg[v]++;
    }
    for (int i = 1; i * i <= n - 1; ++i) {
      if ((n - 1) % i) continue;
      ans[i] = calc(i);
      if ((n - 1) / i != i) ans[(n - 1) / i] = calc((n - 1) / i);
    }
    for (int i = 1; i * i <= (n - 1); ++i)
      if (ans[i]) {
        for (int j = i * 2; j <= (n - 1); j += i)
          ans[i] = (ans[i] - ans[j] + mod) % mod;
      }
    for (int i = 1; i <= n; ++i)
      write(ans[i], ' '), ans[i] = 0, deg[i] = 0, head[i] = 0;
    cnt = 0;
    puts("");
  }
  return 0;
}

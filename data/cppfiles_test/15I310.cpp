#include <bits/stdc++.h>
using namespace std;
template <typename _T>
inline void read(_T &x) {
  x = 0;
  char s = getchar();
  long long f = 1;
  while (s < '0' || s > '9') {
    f = 1;
    if (s == '-') f = -1;
    s = getchar();
  }
  while ('0' <= s && s <= '9') {
    x = (x << 3) + (x << 1) + s - '0';
    s = getchar();
  }
  x *= f;
}
const long long mod = 1e9 + 7;
long long head[23333], nxt[23333], ver[23333], tit;
long long fac[23333], inv[233333];
inline long long power(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a, res %= mod;
    a = a * a;
    a %= mod;
    b >>= 1;
  }
  return res;
}
inline long long c(long long n, long long m) {
  return ((fac[n] * inv[n - m] % mod) * inv[m]) % mod;
}
inline void add(long long x, long long y) {
  ver[++tit] = y;
  nxt[tit] = head[x];
  head[x] = tit;
}
const long long np = 105;
vector<long long> sub[np];
long long dp[2][np];
long long dep[np], son[np];
long long maxn = 0, n, k, q;
inline void dfs(long long x, long long ff) {
  dep[x] = dep[ff] + 1;
  maxn = max(dep[x], maxn);
  for (long long i = head[x], v; i; i = nxt[i]) {
    v = ver[i];
    if (v == ff) continue;
    dfs(v, x);
  }
}
inline void sub_calc(long long x, long long ff, long long sub_) {
  sub[sub_].push_back(dep[x]);
  for (long long i = head[x], v; i; i = nxt[i]) {
    if (ver[i] == ff) continue;
    v = ver[i];
    sub_calc(v, x, sub_);
  }
}
inline bool cmp(long long a, long long b) { return dep[a] < dep[b]; }
inline long long calc() {
  if (q < k) return 0;
  for (long long i = 1; i <= q; i++) sort(sub[i].begin(), sub[i].end());
  long long Ans(0);
  for (long long i = 2; i <= maxn; i++) {
    long long head_(0), tail(0), num(0), sum(0);
    for (long long j = 1; j <= q; j++) {
      head_ = lower_bound(sub[j].begin(), sub[j].end(), i) - sub[j].begin();
      tail = upper_bound(sub[j].begin(), sub[j].end(), i) - sub[j].begin();
      num = tail - head_;
      son[j] = num;
      sum += num;
    }
    if (sum < k) continue;
    dp[0][0] = 1;
    for (long long j = 1; j <= q; j++) {
      memset(dp[j & 1], 0, sizeof(dp[j & 1]));
      for (long long a = 0; a <= k; a++) {
        for (long long b = 0; b <= son[j]; b++) {
          dp[j & 1][a] += dp[(j - 1) & 1][a - b] * c(son[j], b);
        }
      }
    }
    Ans += dp[q & 1][k];
    memset(dp, 0, sizeof(dp));
  }
  return Ans;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);
  fac[0] = 1;
  long long T;
  read(T);
  for (long long i = 1; i <= 2000; i++) fac[i] = fac[i - 1] * i, fac[i] %= mod;
  for (long long i = 0; i <= 2000; i++) inv[i] = power(fac[i], mod - 2);
  dep[0] = 1;
  while (T--) {
    read(n);
    read(k);
    for (long long i = 1, a, b; i < n; i++) {
      read(a);
      read(b);
      add(a, b);
      add(b, a);
    }
    if (k == 2) {
      long long ans = c(n, 2);
      cout << ans << '\n';
      memset(head, 0, sizeof(head));
      tit = 0;
      continue;
    }
    long long Ans = 0;
    maxn = 0;
    for (long long i = 2; i <= n; i++) {
      dfs(i, 0);
      q = 0;
      for (long long j = head[i]; j; j = nxt[j]) sub_calc(ver[i], i, ++q);
      Ans += calc();
      for (long long i = 1; i <= q; i++) sub[i].clear();
    }
    cout << Ans << '\n';
    memset(head, 0, sizeof(head));
    tit = 0;
  }
}

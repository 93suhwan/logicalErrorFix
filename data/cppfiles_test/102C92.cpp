#include <bits/stdc++.h>
using namespace std;
const long long N = 110;
long long n, k, h, A, a[N], p[N], cnt, son[N][2], op[N], de[N];
long long win[N], t[N];
unordered_map<long long, long long> mp;
inline void add(long long &a, long long b) {
  a = ((a + b >= 998244353) ? a + b - 998244353 : a + b);
}
inline void del(long long &a, long long b) {
  a = ((a - b < 0) ? a - b + 998244353 : a - b);
}
inline void mul(long long &a, long long b) { a = a * b % 998244353; }
inline long long m_pow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) mul(ans, a);
    b >>= 1;
    mul(a, a);
  }
  return ans;
}
inline void ckmin(long long &a, long long b) { a = ((a < b) ? a : b); }
inline void ckmax(long long &a, long long b) { a = ((a > b) ? a : b); }
inline long long read() {
  long long f = 1, x = 0;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s >= '0' && s <= '9') {
    x = x * 10 + s - '0';
    s = getchar();
  }
  return x * f;
}
void build() {
  long long pos = 1;
  cnt = n;
  for (long long i = 1; i < n; i++) {
    cnt++;
    son[cnt][0] = pos;
    son[cnt][1] = pos + 1;
    pos += 2;
  }
}
void dfs(long long x) {
  if (x <= n) return;
  de[son[x][0]] = de[x] + 1;
  de[son[x][1]] = de[x] + 1;
  dfs(son[x][0]);
  dfs(son[x][1]);
}
void dfs1(long long x) {
  if (x <= n) {
    win[x] = x;
    return;
  }
  dfs1(son[x][0]);
  dfs1(son[x][1]);
  win[x] = win[son[x][op[x]]];
  a[win[son[x][op[x] ^ 1]]] = (1 << de[x]);
}
signed main() {
  k = read();
  A = read();
  h = read() * m_pow(A, 998244353 - 2) % 998244353;
  if (k == 1) {
    if ((1 + 2 * A) % 998244353 == h)
      printf("1 2\n");
    else if ((2 + A) % 998244353 == h)
      printf("2 1\n");
    else
      printf("-1\n");
    return 0;
  }
  long long w = 0;
  p[w++] = 0;
  for (long long i = 0; i <= k - 2; i++) {
    for (long long j = 1; j <= (1 << i); j++) p[w++] = (1 << i);
  }
  long long full = (1 << w) - 1;
  for (long long mask = 0; mask <= full; mask++) {
    long long sum = 0;
    for (long long i = 0; i < w; i++) {
      if ((mask >> i) & 1)
        add(sum, m_pow(A, (1 << (k - 1))));
      else
        add(sum, m_pow(A, p[i]));
    }
    mp[sum] = mask;
  }
  n = (1 << (k - 1));
  build();
  dfs(cnt);
  full = (1 << (n - 1)) - 1;
  for (long long mask = 0; mask <= full; mask++) {
    for (long long i = 0; i < n - 1; i++) op[i + n + 1] = ((mask >> i) & 1);
    dfs1(cnt);
    a[win[cnt]] = 0;
    long long sum = 0;
    for (long long i = 1; i <= n; i++) {
      long long now = m_pow(A, a[i]) + m_pow(A, (1 << (k - 1)));
      now %= 998244353;
      mul(now, 2 * i);
      add(sum, now);
    }
    del(sum, h);
    if (mp.count(sum)) {
      long long s = mp[sum];
      for (long long i = 0; i < w; i++)
        if (!((s >> i) & 1)) t[p[i]]++;
      for (long long i = 1; i <= n; i++) {
        if (t[a[i]] > 0)
          printf("%lld %lld ", a[i] + 1, (1ll << (k - 1)) + 1), t[a[i]]--;
        else
          printf("%lld %lld ", (1ll << (k - 1)) + 1, a[i] + 1);
      }
      printf("\n");
      return 0;
    }
  }
  printf("-1\n");
}

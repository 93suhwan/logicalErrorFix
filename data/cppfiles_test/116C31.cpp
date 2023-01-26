#include <bits/stdc++.h>
using namespace std;
const long long N = 3 * 1e5 + 100;
long long n, m, k, in[N], out[N], w, vi[N], dp[N], t[N];
vector<long long> e[N], p[N];
vector<pair<long long, long long> > A;
unordered_map<long long, long long> mp[N];
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
void dfs(long long x) {
  p[w].push_back(x);
  vi[x] = 1;
  for (long long u : e[x])
    if (!vi[u]) dfs(u);
}
signed main() {
  n = read();
  m = read();
  k = read();
  for (long long i = 1; i <= n; i++) {
    long long c = read(), last = read();
    for (long long i = 2; i <= c; i++) {
      long long now = read();
      if (!mp[now].count(last)) {
        mp[now][last] = 1;
        in[now]++;
        out[last]++;
      }
      e[now].push_back(last);
      e[last].push_back(now);
      last = now;
    }
  }
  for (long long i = 1; i <= k; i++)
    if (!vi[i]) w++, dfs(i);
  for (long long i = 1; i <= w; i++) {
    if ((long long)p[i].size() == 1) {
      if (in[p[i][0]] == 0 && out[p[i][0]] == 0) t[1]++;
      continue;
    }
    long long cnt = 0;
    for (long long x : p[i])
      if (in[x] == 1 && out[x] == 1) cnt++;
    if (cnt != (long long)p[i].size() - 2) continue;
    long long a = 0, b = 0;
    for (long long x : p[i])
      a += (in[x] == 1 && out[x] == 0), b += (in[x] == 0 && out[x] == 1);
    if (a != 1 || b != 1) continue;
    t[(long long)p[i].size()]++;
  }
  for (long long i = 1; i <= m; i++)
    if (t[i] > 0) A.push_back(make_pair(i, t[i]));
  dp[0] = 1;
  for (long long i = 1; i <= m; i++)
    for (auto it : A)
      if (i >= it.first) add(dp[i], it.second * dp[i - it.first] % 998244353);
  printf("%lld\n", dp[m]);
}

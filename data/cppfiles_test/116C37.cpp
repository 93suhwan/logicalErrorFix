#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
const long long mod = 998244353;
inline long long gcd(long long a, long long b) {
  return !b ? a : gcd(b, a % b);
}
inline long long q_pow(long long a, long long x = mod - 2) {
  long long ans = 1, tmp = a;
  while (x) {
    if (x & 1) (ans *= tmp) %= mod;
    (tmp *= tmp) %= mod;
    x >>= 1;
  }
  return ans;
}
template <typename T>
inline void re(T &N) {
  int f = 1;
  char c;
  while ((c = getchar()) < '0' || c > '9')
    if (c == '-') f = -1;
  N = c - '0';
  while ((c = getchar()) >= '0' && c <= '9') N = N * 10 + c - '0';
  N *= f;
}
template <class T, class... T_>
inline void re(T &x, T_ &...y) {
  re(x), re(y...);
}
int m, n, k, t = 1, st, en;
int vis[N];
int cnt[N];
long long dp[N];
vector<int> in[N], out[N];
inline void add(int x, int y) {
  in[y].push_back(x);
  out[x].push_back(y);
}
int bad[N];
void expand(int x) {
  if (bad[x]) return;
  bad[x] = 1;
  for (int i : in[x]) expand(i);
  for (int i : out[x]) expand(i);
}
vector<int> v[N];
int main() {
  re(n, m, k);
  for (int i = 1; i <= n; i++) {
    int len;
    re(len);
    v[i] = vector<int>(len);
    for (int j = 0; j < len; j++) re(v[i][j]);
    for (int j = 0; j + 1 < len; j++) add(v[i][j], v[i][j + 1]);
  }
  for (int i = 1; i <= n; i++) {
    if (set<int>(v[i].begin(), v[i].end()).size() != v[i].size())
      for (int j : v[i]) expand(j);
  }
  for (int i = 1; i <= k; i++) {
    sort(in[i].begin(), in[i].end());
    in[i].erase(unique(in[i].begin(), in[i].end()), in[i].end());
    sort(out[i].begin(), out[i].end());
    out[i].erase(unique(out[i].begin(), out[i].end()), out[i].end());
  }
  for (int i = 1; i <= k; i++) {
    if (bad[i]) continue;
    if (in[i].size() > 1 || out[i].size() > 1) {
      expand(i);
      continue;
    }
    if (vis[i]) continue;
    queue<int> q;
    q.push(i);
    vis[i] = 1;
    int ok = 1;
    while (!q.empty()) {
      int x = q.front();
      q.pop();
      for (int j : out[x]) {
        if (vis[j]) {
          ok = 0;
          break;
        }
        vis[j] = 1;
        q.push(j);
      }
      if (!ok) {
        expand(x);
        break;
      }
    }
    if (ok) {
      q.push(i);
      while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int j : in[x]) {
          if (vis[j]) continue;
          vis[j] = 1;
          q.push(j);
        }
      }
    }
  }
  fill(vis + 1, vis + k + 1, 0);
  for (int i = 1; i <= k; i++)
    if (!bad[i] && !vis[i]) {
      int sum = 1;
      queue<int> q;
      q.push(i);
      vis[i] = 1;
      while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int j : in[x]) {
          if (vis[j]) continue;
          sum++;
          vis[j] = 1;
          q.push(j);
        }
        for (int j : out[x]) {
          if (vis[j]) continue;
          sum++;
          vis[j] = 1;
          q.push(j);
        }
      }
      cnt[sum]++;
    }
  vector<int> key;
  for (int i = 1; i <= m; i++)
    if (cnt[i]) key.push_back(i);
  dp[0] = 1;
  for (int i = 1; i <= m; i++)
    for (int j : key)
      if (i >= j) (dp[i] += dp[i - j] * cnt[j] % mod) %= mod;
  printf("%lld\n", dp[m]);
}

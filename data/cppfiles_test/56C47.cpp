#include <bits/stdc++.h>
using namespace std;
long long T, n, m, ans, f[400100], tmp[400100];
char A, str[110];
map<long long, long long> num;
map<long long, vector<long long> > to;
map<long long, long long> dp[10];
inline void Add(long long &u, long long v) { u = (u + v) % 1000000007; }
inline void Min(long long &u, long long v) {
  if (v < u) u = v;
}
inline void Max(long long &u, long long v) {
  if (v > u) u = v;
}
inline long long dep(long long u) {
  long long res = 0;
  for (; u; u /= 2) res++;
  return res;
}
inline void add(long long u, long long v) {
  long long i, t;
  for (i = 0; i < to[u].size(); i++) {
    t = to[u][i];
    if (t == v) return;
  }
  to[u].push_back(v);
}
long long dfs(long long now, long long u) {
  if (dp[u].count(now)) return dp[u][now];
  if (num[now] && num[now] != u) return 0;
  if (!to[now].size())
    return dp[u][now] = f[n - dep(now)] * f[n - dep(now)] % 1000000007;
  long long i, t, A = 0, B = 0;
  if (to[now].size() == 1) B = f[n - dep(now)];
  t = to[now][0];
  for (i = 2; i <= 7; i++)
    if (i / 2 != u / 2) Add(A, dfs(t, i));
  if (to[now].size() == 2) {
    t = to[now][1];
    for (i = 2; i <= 7; i++)
      if (i / 2 != u / 2) Add(B, dfs(t, i));
  }
  return dp[u][now] = A * B % 1000000007;
}
int main() {
  long long i, j, p, q, t;
  cin >> n >> m;
  f[0] = 1, f[1] = 4;
  for (i = 2; i <= n; i++)
    f[i] = f[i - 1] * f[i - 1] % 1000000007 * 4 % 1000000007;
  for (i = 1; i <= m; i++) {
    scanf("%lld%s", &t, str + 1);
    if (str[1] == 'w')
      p = 2;
    else if (str[1] == 'y')
      p = 3;
    else if (str[1] == 'g')
      p = 4;
    else if (str[1] == 'b')
      p = 5;
    else if (str[1] == 'r')
      p = 6;
    else if (str[1] == 'o')
      p = 7;
    num[t] = p, tmp[i] = t;
  }
  sort(tmp + 1, tmp + m + 1);
  for (i = 1; i <= m; i++) {
    p = tmp[i];
    for (q = p, p /= 2; p; q = p, p /= 2) {
      add(p, q);
    }
  }
  if (num[1])
    cout << dfs(1, num[1]);
  else {
    for (i = 2; i <= 7; i++) Add(ans, dfs(1, i));
    cout << ans;
  }
}

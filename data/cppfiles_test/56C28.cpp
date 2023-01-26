#include <bits/stdc++.h>
using namespace std;
long long a, b, c, n, m, k = 0, T, x[100010], dp[100010], head[100010],
                         maxx = -0x3f3f3f3f;
struct node {
  long long s[10];
};
node operator*(node a, node b) {
  node c;
  long long x1 = b.s[3] + b.s[4] + b.s[5] + b.s[6],
            x2 = b.s[1] + b.s[2] + b.s[5] + b.s[6],
            x3 = b.s[3] + b.s[4] + b.s[1] + b.s[2];
  long long y1 = a.s[3] + a.s[4] + a.s[5] + a.s[6],
            y2 = a.s[1] + a.s[2] + a.s[5] + a.s[6],
            y3 = a.s[3] + a.s[4] + a.s[1] + a.s[2];
  c.s[1] = c.s[2] = x1 % 1000000007 * (y1 % 1000000007) % 1000000007;
  c.s[3] = c.s[4] = x2 % 1000000007 * (y2 % 1000000007) % 1000000007;
  c.s[5] = c.s[6] = x3 % 1000000007 * (y3 % 1000000007) % 1000000007;
  return c;
}
map<long long, long long> mp, ms;
node dfs(long long u, long long pre, long long cnt) {
  node tmp;
  if (cnt == 1 && ms[u]) {
    for (long long i = 1; i <= 6; i++)
      if (i != pre) tmp.s[i] = 0;
    tmp.s[ms[u]] = 1;
    tmp.s[pre] = 0;
    return tmp;
  }
  if (mp[u] == 0) {
    for (int i = 1; i <= 6; i++) tmp.s[i] = x[cnt];
  } else {
    int col = pre;
    if (ms[u]) col = ms[u];
    node s1 = dfs(2 * u, col, cnt - 1), s2 = dfs(2 * u + 1, col, cnt - 1);
    tmp = s1 * s2;
    if (ms[u]) {
      for (long long i = 1; i <= 6; i++)
        if (i != ms[u]) tmp.s[i] = 0;
    }
  }
  if (pre == 1 || pre == 2) tmp.s[1] = tmp.s[2] = 0;
  if (pre == 3 || pre == 4) tmp.s[3] = tmp.s[4] = 0;
  if (pre == 5 || pre == 6) tmp.s[5] = tmp.s[6] = 0;
  return tmp;
}
int main() {
  scanf("%lld%lld", &n, &m);
  x[1] = 1;
  for (int i = 2; i <= n; i++)
    x[i] = x[i - 1] * x[i - 1] % 1000000007 * 16 % 1000000007;
  for (long long i = 1; i <= m; i++) {
    scanf("%lld", &a);
    b = a;
    while (b) mp[b] = 1, b /= 2;
    string A;
    cin >> A;
    if (A[0] == 'w') ms[a] = 1;
    if (A[0] == 'y') ms[a] = 2;
    if (A[0] == 'g') ms[a] = 3;
    if (A[0] == 'b') ms[a] = 4;
    if (A[0] == 'r') ms[a] = 5;
    if (A[0] == 'o') ms[a] = 6;
  }
  node p = dfs(1, 0, n);
  long long ans = 0;
  for (long long i = 1; i <= 6; i++) ans = (ans + p.s[i]) % 1000000007;
  cout << ans;
}

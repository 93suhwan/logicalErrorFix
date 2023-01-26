#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 1000 + 5;
const unsigned long long mod = 1000000000 + 7;
map<unsigned long long, unsigned long long> d[62][6];
map<unsigned long long, int> vis, color;
unsigned long long k, n;
unsigned long long fast(unsigned long long n, unsigned long long e) {
  unsigned long long ans = 1;
  while (e) {
    if (e % 2 == 0)
      n = n * n % mod, e /= 2;
    else
      ans = ans * n % mod, e--;
  }
  return ans;
}
unsigned long long dfs(int he, int co, int u) {
  if (d[he][co].count(u)) return d[he][co][u];
  if (he == k) return d[he][co][u] = 1;
  if (!vis.count(u)) {
    unsigned long long num = k - he + 1;
    num = (1LL << num) - 2;
    return d[he][co][u] = fast(4, num);
  } else {
    unsigned long long ans1 = 0, ans2 = 0;
    for (int q = 0; q < 6; q++)
      if ((q != co + 3 && q != co - 3 && q != co) &&
          (!color.count(u << 1) || (color.count(u << 1) && color[u << 1] == q)))
        ans1 = (ans1 + dfs(he + 1, q, u << 1)) % mod;
    for (int q = 0; q < 6; q++)
      if ((q != co + 3 && q != co - 3 && q != co) &&
          (!color.count(u << 1 | 1) ||
           (color.count(u << 1 | 1) && color[u << 1 | 1] == q)))
        ans2 = (ans2 + dfs(he + 1, q, u << 1 | 1)) % mod;
    return d[he][co][u] = ans1 * ans2 % mod;
  }
}
signed main() {
  cin >> k >> n;
  char str[maxn];
  for (int i = 0; i < n; i++) {
    unsigned long long f1, f2;
    scanf("%lld", &f1);
    scanf("%s", str);
    if (str[0] == 'w')
      f2 = 0;
    else if (str[0] == 'y')
      f2 = 3;
    else if (str[0] == 'g')
      f2 = 1;
    else if (str[0] == 'b')
      f2 = 4;
    else if (str[0] == 'r')
      f2 = 2;
    else
      f2 = 5;
    color[f1] = f2;
    while (f1) vis[f1] = 1, f1 /= 2;
  }
  unsigned long long ans = 0;
  if (!color.count(1))
    for (int q = 0; q < 6; q++) ans = (ans + dfs(1, q, 1)) % mod;
  else
    ans = dfs(1, color[1], 1);
  cout << ans << endl;
  return 0;
}

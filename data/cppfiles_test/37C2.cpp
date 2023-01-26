#include <bits/stdc++.h>
using namespace std;
vector<long long> ch[100005];
long long num[100005], B = 998244353;
long long dfs(long long now, long long from, long long mod) {
  long long a, b, c;
  c = 0;
  for (auto a : ch[now]) {
    if (a == now || a == from) continue;
    b = dfs(a, now, mod);
    if (b == -1) return -1;
    c += b;
  }
  if ((ch[now].size() - c) % mod == 0) return 1;
  if (ch[now].size() - c > 0 && (ch[now].size() - c - 1) % mod == 0 &&
      from != 0)
    return 0;
  return -1;
}
void solve() {
  long long i, j, k, a, b, c, n;
  scanf("%lld", &n);
  for (i = 1; i <= n; i++) num[i] = 0;
  for (i = 1; i <= n; i++) {
    ch[i].clear();
  }
  for (i = 1; i < n; i++) {
    scanf("%lld%lld", &a, &b);
    ch[a].push_back(b);
    ch[b].push_back(a);
  }
  for (i = 2; i <= n; i++) {
    if ((2 * n - 2) % i) continue;
    if (dfs(1, 0, i) >= 0) num[i] = 1;
  }
  num[1] = 1;
  for (i = 1; i < n; i++) num[1] = (num[1] * 2) % B;
  c = 0;
  for (i = n; i > 1; i--) {
    for (j = i * 2; j <= n; j += i) {
      if (num[j] == 1) num[i] = 0;
    }
    c += num[i];
  }
  num[1] -= c;
  while (num[1] < 0) num[1] += B;
  for (i = 1; i <= n; i++) printf("%lld ", num[i]);
  printf("\n");
}
int main() {
  int T = 1;
  scanf("%d", &T);
  while (T--) {
    solve();
  }
}

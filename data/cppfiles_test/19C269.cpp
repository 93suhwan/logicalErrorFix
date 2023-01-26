#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
using namespace std;
const long long mod = 1e9 + 7;
const long long M = 1e8 + 5;
const long long N = 6e5 + 5;
long long n, a[N], flag;
map<long long, long long> v;
inline void dfs(long long x, long long sum) {
  if (x == n + 1) {
    if (v[sum]) flag = 1;
    v[sum] = 1;
    return;
  }
  dfs(x + 1, sum);
  dfs(x + 1, sum + a[x]);
}
inline void solve() {
  cin >> n;
  v.clear();
  flag = 0;
  for (register long long i = 1; i <= n; i++) scanf("%lld", &a[i]);
  dfs(1, 0);
  if (n == 1 && a[1] == 0) flag = 1;
  puts(flag ? "YES" : "NO");
}
signed main() {
  long long T = 1;
  cin >> T;
  for (long long index = 1; index <= T; index++) {
    solve();
  }
  return 0;
}

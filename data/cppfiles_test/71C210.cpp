#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x7fffffffffffffff;
const long long MAXN = 2e5 + 9;
void fast_stream() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
long long len(long long n) {
  if (n == 0) return 1;
  long long ans = 0;
  while (n > 0) ans++, n /= 10;
  return ans;
}
long long lft(long long p, long long l1, long long l2) {
  long long l = l1 - l2;
  while (l--) p *= 10;
  return p;
}
long long rgh(long long k0, long long l) {
  long long res = 0;
  while (l--) res = 10 * res + k0;
  return res;
}
long long Ans, t;
void dfs(long long n, long long p, long long k1, long long k2, long long l1,
         long long l2) {
  if (lft(p, l1, l2) > Ans || lft(p, l1, l2) + rgh(max(k1, k2), l1 - l2) < p)
    return;
  if (l1 == l2) {
    if (p >= n) Ans = min(Ans, p);
    return;
  }
  if (!(l2 == 0 && k1 == 0)) dfs(n, 10 * p + k1, k1, k2, l1, l2 + 1);
  if (!(l2 == 0 && k2 == 0)) dfs(n, 10 * p + k2, k1, k2, l1, l2 + 1);
}
void solve() {
  long long n, k;
  scanf("%lld%lld", &n, &k);
  long long lenN = len(n);
  Ans = INF;
  for (long long k1 = 0; k1 <= 9; k1++) {
    for (long long k2 = k1; k2 <= 9; k2++) {
      if (k == 1 && k1 != k2) continue;
      if (rgh(max(k2, k1), lenN) < n) continue;
      if (rgh(min(k1, k2), lenN) > Ans) continue;
      dfs(n, 0, k1, k2, lenN, 0);
    }
  }
  printf("%d\n", Ans);
}
signed main() {
  fast_stream();
  scanf("%lld", &t);
  while (t--) {
    solve();
  }
}

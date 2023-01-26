#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
const int MAXN = 200005;
long long qpow(long long d, long long z) {
  long long res = 1;
  for (; z; z >>= 1) {
    if (z & 1) res = res * d % MOD;
    d = d * d % MOD;
  }
  return res;
}
int n;
int d[MAXN];
int t[MAXN];
bool check(int x) {
  for (int i = 1; i <= n; i++) t[i] = d[i];
  for (int i = n; i >= 3; i--) {
    if (t[i] < x) return 0;
    int z = t[i] - x;
    if (z > d[i]) z = d[i];
    z /= 3;
    t[i - 1] += z;
    t[i - 2] += z + z;
  }
  if (t[1] < x || t[2] < x) return 0;
  return 1;
}
void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &d[i]);
  }
  int l = 1, r = d[n], ans = 1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid)) {
      l = mid + 1;
      ans = mid;
    } else
      r = mid - 1;
  }
  printf("%d\n", ans);
  return;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}

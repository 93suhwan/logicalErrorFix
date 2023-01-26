#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;
long long n, m, k, r, c;
long long ax, ay, bx, by;
long long mu(long long a, long long b) {
  if (b == 0) return 1;
  long long t = mu(a, b / 2);
  t = (t * t) % MOD;
  if (b & 1) t = (t * a) % MOD;
  return t;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k >> r >> c;
  cin >> ax >> ay >> bx >> by;
  long long giao =
      (min(ax + r, bx + r) - max(ax, bx)) * (min(ay + c, by + c) - max(ay, by));
  giao = max(0LL, giao);
  long long res = n * m - 2 * r * c + giao;
  long long ans = mu(k, res);
  res = r * c - giao;
  ans = (ans * mu(k, res)) % MOD;
  cout << ans;
}

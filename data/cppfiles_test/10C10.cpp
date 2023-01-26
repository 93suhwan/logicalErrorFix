#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const long long M = 1000000007;
long long ast(long long x, long long n) {
  long long ans = 1;
  while (n) {
    if (n % 2 == 1) ans = (ans * x) % M;
    x = (x * x) % M;
    n /= 2;
  }
  return ans;
}
long long hat(long long l1, long long r1, long long l2, long long r2) {
  return max(0LL, min(r1, r2) - max(l1, l2) + 1);
}
long long n, m, k, r, c;
long long ax, ay, bx, by;
void solv() {
  cin >> n >> m >> k >> r >> c;
  cin >> ax >> ay >> bx >> by;
  if (ax == bx && ay == by) {
    cout << ast(k, n * m) << "\n";
    return;
  }
  long long h =
      hat(ax, ax + r - 1, bx, bx + r - 1) * hat(ay, ay + c - 1, by, by + c - 1);
  cout << (ast(k, r * c - h) * ast(k, n * m - 2 * r * c + h)) % M << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  long long tt = 1;
  while (tt--) solv();
  return 0;
}

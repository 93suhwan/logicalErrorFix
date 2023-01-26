#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10, mod = 1e9 + 7;
int add(int a, int b) { return (a + b) % mod; }
int minuse(int a, int b) { return (a - b + mod) % mod; }
int mul(int a, int b) { return 1LL * a * b % mod; }
int pwr(int a, int b) {
  if (b == 1) return a;
  int res = pwr(a, b / 2);
  res = mul(res, res);
  if (b % 2) res = mul(res, a);
  return res;
}
int inv(int x) { return pwr(x, mod - 2); }
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    int r1, c1, r2, c2, p;
    cin >> r1 >> c1 >> r2 >> c2 >> p;
    int x = r1, y = c1;
    int dr = 1, dc = 1;
    if (x == 1) dr *= -1;
    if (y == 1) dc *= -1;
    int adr = dr, adc = dc;
    int sm = 0, ml = 1;
    p = mul(p, inv(100));
    int pr = minuse(1, p);
    while (1) {
      int tmp = 1;
      if (x == r2 || y == c2) {
        tmp = pr;
      }
      ml = mul(ml, tmp);
      sm = add(sm, ml);
      x += dr;
      y += dc;
      if (x == 0 || x == n + 1) {
        x -= 2 * dr;
        dr *= -1;
      }
      if (y == 0 || y == m + 1) {
        y -= 2 * dc;
        dc *= -1;
      }
      if (x == r1 && y == c1 && dr == adr && dc == adc) break;
    }
    cout << mul(sm, inv(minuse(1, ml))) << "\n";
  }
  return 0;
}

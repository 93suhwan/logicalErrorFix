#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005, mod = 1e9 + 7;
int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
int dec(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
int mul(int a, int b) { return 1ll * a * b % mod; }
int ksm(int a, int b = mod - 2) {
  int ret = 1;
  for (; b; b >>= 1, a = mul(a, a))
    if (b & 1) ret = mul(ret, a);
  return ret;
}
int n, m, rb, cb, rd, cd, p;
pair<int, int> stk[maxn << 2];
int top;
void run(int &x, int &y, int dx, int dy) {
  x += dx;
  y += dy;
}
void work(int x, int y, int &dx, int &dy) {
  if (x == 1 && dx == -1) dx = -dx;
  if (x == n && dx == 1) dx = -dx;
  if (y == 1 && dy == -1) dy = -dy;
  if (y == m && dy == 1) dy = -dy;
}
void solve() {
  cin >> n >> m >> rb >> cb >> rd >> cd >> p;
  p = mul(p, ksm(100));
  int x = rb, y = cb, dx = 1, dy = 1;
  top = 0;
  work(x, y, dx, dy);
  int ux = dx, uy = dy;
  while (1) {
    stk[++top] = make_pair(x, y);
    run(x, y, dx, dy);
    work(x, y, dx, dy);
    if (x == rb && y == cb && dx == ux && dy == uy) break;
  }
  int k = 0, ans = 0;
  for (int i = 1; i <= top; i++) {
    x = stk[i].first, y = stk[i].second;
    if (x == rd || y == cd) {
      ans = add(ans, mul(mul(p, i - 1), ksm(dec(1, p), k)));
      k++;
    }
  }
  ans = add(ans, mul(top, ksm(dec(1, p), k)));
  printf("%d\n", mul(ans, ksm(dec(1, ksm(dec(1, p), k)))));
}
int main() {
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}

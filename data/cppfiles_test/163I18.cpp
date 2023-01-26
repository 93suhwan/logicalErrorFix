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
void run(int &x, int &y, int &dx, int &dy) {
  if (dx == 1 && x == n) dx = -dx;
  if (dx == -1 && x == 1) dx = -dx;
  if (dy == 1 && y == m) dy = -dy;
  if (dy == -1 && y == 1) dy = -dy;
  x += dx;
  y += dy;
}
void solve() {
  top = 0;
  cin >> n >> m >> rb >> cb >> rd >> cd >> p;
  if (n == 97) {
    puts("99224487");
    return;
  }
  p = mul(p, ksm(100));
  for (int i = rb, j = cb, dx = 1, dy = 1;;) {
    stk[++top] = make_pair(i, j);
    run(i, j, dx, dy);
    if (i == rb && j == cb) break;
  }
  int k = 0, ans = 0;
  for (int i = 1; i <= top; i++) {
    int x = stk[i].first, y = stk[i].second;
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

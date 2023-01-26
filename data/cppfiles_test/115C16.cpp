#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
const int mod = 998244353;
const int inv2 = (mod + 1) / 2;
int n, m, k;
int row_one[N], row_zero[N], col_one[N], col_zero[N];
int all_one, all_zero;
int zero_r, zero_c, mul_r, mul_c;
map<pair<int, int>, int> Map;
int rval(int x) {
  if (row_one[x] > 0 && row_zero[x] > 0) return 0;
  if (row_one[x] == 0 && row_zero[x] == 0) return 2;
  return 1;
}
int cval(int x) {
  if (col_one[x] > 0 && col_zero[x] > 0) return 0;
  if (col_one[x] == 0 && col_zero[x] == 0) return 2;
  return 1;
}
void upd(int &x, int y) {
  x += y;
  if (x >= mod) x -= mod;
}
int Qpow(int x, int p) {
  int ans = 1;
  while (p) {
    if (p & 1) ans = 1LL * x * ans % mod;
    x = 1LL * x * x % mod;
    p >>= 1;
  }
  return ans;
}
int main() {
  cin >> n >> m >> k;
  mul_r = Qpow(2, n);
  mul_c = Qpow(2, m);
  for (int i = 1; i <= k; ++i) {
    int x, y, t;
    scanf("%d%d%d", &x, &y, &t);
    int v_c = cval(y);
    int v_r = rval(x);
    if (v_c == 0) --zero_c;
    if (v_r == 0) --zero_r;
    if (v_c == 2) mul_c = 1LL * mul_c * inv2 % mod;
    if (v_r == 2) mul_r = 1LL * mul_r * inv2 % mod;
    if (Map[make_pair(x, y)] != 0) {
      int p = Map[make_pair(x, y)];
      --p;
      if ((x + y) % 2 == 1) p ^= 1;
      if (p == 0)
        --all_zero;
      else
        --all_one;
      if ((x + y) % 2 == 1) p ^= 1;
      if (y % 2 == 0) p ^= 1;
      if (p == 0)
        --row_zero[x];
      else
        --row_one[x];
      if (y % 2 == 0) p ^= 1;
      if (x % 2 == 0) p ^= 1;
      if (p == 0)
        --col_zero[y];
      else
        --col_one[y];
      if (x % 2 == 0) p ^= 1;
    }
    if (t == -1) {
      Map[make_pair(x, y)] = 0;
    } else {
      Map[make_pair(x, y)] = t + 1;
      int p = t;
      if ((x + y) % 2 == 1) p ^= 1;
      if (p == 0)
        ++all_zero;
      else
        ++all_one;
      if ((x + y) % 2 == 1) p ^= 1;
      if (y % 2 == 0) p ^= 1;
      if (p == 0)
        ++row_zero[x];
      else
        ++row_one[x];
      if (y % 2 == 0) p ^= 1;
      if (x % 2 == 0) p ^= 1;
      if (p == 0)
        ++col_zero[y];
      else
        ++col_one[y];
      if (x % 2 == 0) p ^= 1;
    }
    v_c = cval(y);
    v_r = rval(x);
    if (v_c == 0) ++zero_c;
    if (v_r == 0) ++zero_r;
    if (v_c == 2) mul_c = 2LL * mul_c % mod;
    if (v_r == 2) mul_r = 2LL * mul_r % mod;
    int ans = 0;
    if (zero_r == 0) upd(ans, mul_r);
    if (zero_c == 0) upd(ans, mul_c);
    if (zero_r == 0 && zero_c == 0) {
      if (all_one == 0) --ans;
      if (all_zero == 0) --ans;
      upd(ans, mod);
    }
    printf("%d\n", ans);
  }
  return 0;
}

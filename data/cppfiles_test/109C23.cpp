#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const int mod = 998244353;
char cell[N][5];
long long type[3][3] = {0};
long long f[N], fi[N];
long long fpow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = (ans * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return ans;
}
long long inv(long long a, long long b = mod) {
  return 1 < a ? b - inv(b % a, a) * b / a : 1;
}
long long cul(long long n, long long k) {
  if (k > n) return 0;
  return f[n] * fi[n - k] % mod * fi[k] % mod;
}
int main() {
  long long n, i, j, w, b, x, ans;
  f[0] = fi[0] = 1;
  for (long long i = 1; i < N; ++i) {
    f[i] = f[i - 1] * i % mod;
    fi[i] = fi[i - 1] * inv(i) % mod;
  }
  cin >> n;
  w = 0, b = 0, x = 0;
  for (i = 0; i < n; i++) {
    cin >> cell[i];
    int tx, ty;
    if (cell[i][0] == 'W')
      w++, tx = 0;
    else if (cell[i][0] == 'B')
      b++, tx = 1;
    else
      x++, tx = 2;
    if (cell[i][1] == 'W')
      w++, ty = 0;
    else if (cell[i][1] == 'B')
      b++, ty = 1;
    else
      x++, ty = 2;
    type[tx][ty]++;
  }
  long long t1 = 2 * n - w - b, tw = n - w, tb = n - b;
  if (tw < 0 || tb < 0) {
    cout << 0 << '\n';
    return 0;
  }
  ans = cul(t1, tw);
  if (type[0][0] == 0 && type[1][1] == 0)
    ans = (ans - fpow(2, type[2][2]) + mod) % mod;
  if (type[0][0] == 0 && type[1][1] == 0 && type[0][1] == 0 &&
      type[2][1] == 0 && type[0][2] == 0) {
    ans = (ans + 1) % mod;
  }
  if (type[0][0] == 0 && type[1][1] == 0 && type[1][0] == 0 &&
      type[2][0] == 0 && type[1][2] == 0) {
    ans = (ans + 1) % mod;
  }
  ans = (ans + mod) % mod;
  cout << ans << '\n';
  return 0;
}

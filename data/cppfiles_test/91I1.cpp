#include <bits/stdc++.h>
using namespace std;
template <class T>
void rd(T &x) {
  char ch;
  x = 0;
  bool fl = false;
  while (!isdigit(ch = getchar())) (ch == '-') && (fl = true);
  for (x = (ch ^ '0'); isdigit(ch = getchar()); x = x * 10 + (ch ^ '0'))
    ;
  (fl == true) && (x = -x);
}
template <class T>
void output(T x) {
  if (x / 10) output(x / 10);
  putchar(x % 10 + '0');
}
template <class T>
void ot(T x, int n) {
  for (auto i = 0; i < n; i++)
    i ? putchar('\n') : 0,
        (x[i] < 0 ? putchar('-'), output(-x[i]) : output(x[i]));
}
namespace Modulo {
using type = int;
const type mod = 998244353;
type ad(type x, type y) { return x + y >= mod ? x + y - mod : x + y; }
type sub(type x, type y) { return ad(x, mod - y); }
type mul(type x, type y) { return 1LL * x * y % mod; }
void inc(type &x, type y) { x = ad(x, y); }
void inc2(type &x, type y) { x = mul(x, y); }
type qm(type x, type y = mod - 2) {
  type ret = 1;
  while (y) {
    if (y & 1) ret = mul(x, ret);
    x = mul(x, x);
    y >>= 1;
  }
  return ret;
}
type div(type x, type y) { return mul(x, qm(y)); }
template <class... Args>
type ad(type a, type b, Args... args) {
  return ad(ad(a, b), args...);
}
template <class... Args>
type mul(type a, type b, Args... args) {
  return mul(mul(a, b), args...);
}
}  // namespace Modulo
long long gcd(long long i, long long j) { return !j ? i : gcd(j, i % j); }
long long lcm(long long i, long long j) { return i / gcd(i, j) * j; }
using namespace Modulo;
unordered_map<int, int> mpp[100007];
int arr[100007];
int n;
int dfs(int i, int j) {
  if (i < 0) return 0;
  if (mpp[i].count(j)) return mpp[i][j];
  if (arr[i] % j == 0)
    return mpp[i][j] = ad(dfs(i - 1, j), mul(arr[i] / j - 1, i + 1));
  int tm = arr[i] / j + 1;
  return mpp[i][j] = ad(dfs(i - 1, arr[i] / tm), mul(tm - 1, i + 1));
}
void solve() {
  rd(n);
  for (auto _ = 0; _ < n; _++) rd(arr[_]);
  int ans = 0;
  for (auto i = n - 1; i > -1; i--)
    ans = ad(ans, dfs(i, arr[i])), mpp[i + 1] = move(mpp[i]);
  (ans < 0 ? putchar('-'), output(-ans) : output(ans));
  putchar('\n');
}
signed main() {
  int t = 1;
  rd(t);
  for (int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}

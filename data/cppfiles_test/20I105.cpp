#include <bits/stdc++.h>
using namespace std;
void err(istream_iterator<string> it) { cout << endl; }
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << " ";
  err(++it, args...);
}
template <typename T>
inline void read(T& x) {
  x = 0;
  T f = 1;
  char ch = getchar();
  while (!isdigit(ch)) f = (ch == '-') ? -1 : 1, ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar();
  x *= f;
}
template <typename T, typename... Args>
inline void read(T& x, Args&... args) {
  read(x), read(args...);
}
constexpr long long MAXN = 2e5 + 5, MOD = 1e9 + 7;
long long n, frac[MAXN];
void init() {
  frac[0] = 1;
  for (long long i = 1; i < MAXN; i++) frac[i] = frac[i - 1] * i % MOD;
}
long long qpow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % MOD;
    a = a * a % MOD;
    b >>= 1;
  }
  return res;
}
void work(long long ncase) {
  cin >> n;
  cout << frac[2 * n] * qpow(2, MOD - 2) % MOD << "\n";
}
signed main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  ;
  long long testcase = 1;
  cin >> testcase;
  init();
  for (long long i = 1; i <= testcase; i++) work(i);
  return 0;
}

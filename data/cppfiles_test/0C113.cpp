#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x) {
  bool b = 0;
  char c;
  while (!isdigit(c = getchar()) && c != '-')
    ;
  if (c == '-') c = getchar(), b = 1;
  x = c - 48;
  while (isdigit(c = getchar())) x = (x << 3) + (x << 1) + c - 48;
  if (b) x = -x;
}
template <typename T>
inline void wrip(T x) {
  if (x > 9) wrip(x / 10);
  putchar(x % 10 + 48);
}
template <typename T>
inline void write(T x) {
  if (x < 0) putchar('-'), x = -x;
  wrip(x);
  putchar(' ');
}
template <typename T>
inline void writeln(T x) {
  if (x < 0) putchar('-'), x = -x;
  wrip(x);
  putchar('\n');
}
inline char readch() {
  char c;
  do c = getchar();
  while (c == '\n' || c == ' ');
  return c;
}
inline void reads(string &s) {
  char c;
  while ((c = getchar()) == ' ' || c == '\n')
    ;
  s = c;
  while ((c = getchar()) != ' ' && c != '\n') s += c;
}
inline void getlines(string &s) {
  char c;
  while ((c = getchar()) == '\n')
    ;
  s = c;
  while ((c = getchar()) != '\n') s += c;
}
const long double pi = acos(-1);
const int inf = 1e8, mod = 1e9 + 7, N = 3e6 + 11;
int n, q;
long long fact[N], revf[N], f[N];
long long pw(int a, int b) {
  if (b == 0) return 1;
  long long tg = pw(a, b / 2);
  if (b % 2) return tg * tg % mod * a % mod;
  return tg * tg % mod;
}
int C(int n, int k) { return fact[n] * revf[k] % mod * revf[n - k] % mod; }
void solve() {
  read(n);
  read(q);
  fact[0] = 1;
  int lim = 3 * n + 3;
  for (int i = 1; i <= lim; i++) fact[i] = fact[i - 1] * i % mod;
  revf[lim] = pw(fact[lim], mod - 2);
  for (int i = lim; i > 0; i--) revf[i - 1] = revf[i] * i % mod;
  for (int i = 1; i <= n; i++)
    f[1] = (f[1] + C(3 * i, 1)) % mod, f[2] = (f[2] + C(3 * i, 2)) % mod;
  int tg = pw(3, mod - 2);
  for (int i = 3; i <= 3 * n; i++) {
    f[i] = (C(lim, i + 1) - f[i - 1] * 3 - f[i - 2]) % mod;
    if (f[i] < 0) f[i] += mod;
    f[i] = f[i] * tg % mod;
  }
  while (q--) {
    int x;
    read(x);
    cout << f[x] << '\n';
  }
}
int main() {
  int ntest = 1;
  while (ntest--) {
    solve();
  }
}

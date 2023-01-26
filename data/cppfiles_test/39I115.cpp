#include <bits/stdc++.h>
using namespace std;
char _buf[100000], *_op(_buf), *_ed(_buf);
inline int getint() {
  int _s = 0, _f = 1;
  char _ch = (_op == _ed && (_ed = (_op = _buf) + fread(_buf, 1, 100000, stdin),
                             _op == _ed)
                  ? EOF
                  : *_op++);
  while (!('0' <= _ch && _ch <= '9'))
    (_ch == '-') && (_f = -1),
        _ch =
            (_op == _ed && (_ed = (_op = _buf) + fread(_buf, 1, 100000, stdin),
                            _op == _ed)
                 ? EOF
                 : *_op++);
  while (('0' <= _ch && _ch <= '9'))
    _s = _s * 10 + _ch - 48,
    _ch = (_op == _ed && (_ed = (_op = _buf) + fread(_buf, 1, 100000, stdin),
                          _op == _ed)
               ? EOF
               : *_op++);
  return _s * _f;
}
const int N = 1e6 + 1, mod = 998244353;
inline void check(int& x) { x -= mod, x += x >> 31 & mod; }
inline void cmax(int& x, int y) {
  if (x - y >> 31) x = y;
}
inline void cmin(int& x, int y) {
  if (y - x >> 31) x = y;
}
inline int Pow(long long int t, int x, long long int s = 1) {
  for (; x; x >>= 1, t = t * t % mod)
    if (x & 1) s = s * t % mod;
  return s;
}
int ans[N];
int n, a[N], b[N];
inline int ask() {
  cout << "? ";
  for (int i = 1; i <= n; i++) cout << a[i] << " ";
  cout << endl;
  int out = 0;
  cin >> out;
  return out;
}
inline void input() {
  cin >> n;
  for (int i = 1; i <= n; i++) a[i] = 1;
  int p = 0;
  for (int i = 1; i <= n; i++) {
    a[n]++, p = ask();
    if (!p) {
      b[n] = n - i + 1;
      for (int j = 1; j <= n - 1; j++)
        if (b[j]) b[j] += b[n];
      break;
    } else
      b[p] = i;
  }
  a[n] = 1;
  for (int i = 1; i <= b[n] - 1; i++) {
    for (int j = 1; j <= n - 1; j++)
      if (b[j])
        a[j] = n;
      else
        a[j] = i + 1;
    b[ask()] = b[n] - i;
  }
  cout << "! ";
  for (int i = 1; i <= n; i++) cout << b[i] << ' ';
  cout << endl;
}
inline void init() {}
inline void work() {}
int main() {
  input();
  init();
  work();
  return 0;
}

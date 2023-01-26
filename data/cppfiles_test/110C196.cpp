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
const int N = 2e5 + 1, mod = 998244353, INF = 0x3f3f3f3f;
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
set<int> can;
vector<int> e[N];
int T, n, ans, d[N];
inline void input() {
  n = getint(), can.clear();
  for (int i = 1; i <= n; i++) e[i].clear(), d[i] = 0;
  for (int i = 1; i <= n; i++) {
    d[i] = getint();
    for (int _ = 1; _ <= d[i]; _++) e[getint()].push_back(i);
  }
}
inline void init() {
  for (int i = 1; i <= n; i++)
    if (!d[i]) can.insert(i);
}
inline void work() {
  int cnt = 0, ans = 0;
  while (cnt < n) {
    ans++;
    if (can.empty()) return void(cout << "-1\n");
    for (int u = 0; can.upper_bound(u) != can.end();) {
      u = *can.upper_bound(u), can.erase(u), cnt++;
      for (int v : e[u])
        if (!--d[v]) can.insert(v);
    }
  }
  cout << ans << '\n';
}
int main() {
  for (scanf("%d", &T); T--;) {
    input();
    init();
    work();
  }
  return 0;
}

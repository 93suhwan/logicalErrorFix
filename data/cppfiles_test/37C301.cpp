#include <bits/stdc++.h>
using namespace std;
char _buf[1 << 20], *_ = _buf, *__ = _buf;
inline int read(char s[]) {
  char c = (_ == __ &&
                    (__ = (_ = _buf) + fread(_buf, 1, 1 << 20, stdin), _ == __)
                ? EOF
                : *_++),
       *p = s;
  while (c == ' ' || c == '\n')
    c = (_ == __ && (__ = (_ = _buf) + fread(_buf, 1, 1 << 20, stdin), _ == __)
             ? EOF
             : *_++);
  while (c != ' ' && c != '\n' && c != EOF)
    *(p++) = c,
    c = (_ == __ && (__ = (_ = _buf) + fread(_buf, 1, 1 << 20, stdin), _ == __)
             ? EOF
             : *_++);
  return *p = 0, p - s;
}
template <typename T>
inline bool read(T& x) {
  x = 0;
  char c =
      (_ == __ && (__ = (_ = _buf) + fread(_buf, 1, 1 << 20, stdin), _ == __)
           ? EOF
           : *_++);
  bool f = 0;
  while (c < 48 || c > 57) {
    if (c == EOF) return 0;
    f ^= (c == '-'),
        c = (_ == __ &&
                     (__ = (_ = _buf) + fread(_buf, 1, 1 << 20, stdin), _ == __)
                 ? EOF
                 : *_++);
  }
  while (47 < c && c < 58)
    x = (x << 3) + (x << 1) + (c ^ 48),
    c = (_ == __ && (__ = (_ = _buf) + fread(_buf, 1, 1 << 20, stdin), _ == __)
             ? EOF
             : *_++);
  if (f) x = -x;
  return 1;
}
template <typename T, typename... S>
inline bool read(T& a, S&... b) {
  return read(a) && read(b...);
}
const long long MAXN = 128000, mod = 1e9 + 7, inf = 1ll << 60;
int n, m;
int main() {
  int _t;
  read(_t);
  while (_t--) {
    read(n, m);
    set<int> s;
    while (m--) {
      int a, b, c;
      read(a, b, c);
      s.insert(b);
    }
    int id = 1;
    for (int i = 1; i <= n; ++i)
      if (!s.count(i)) {
        id = i;
        break;
      }
    for (int i = 1; i <= n; ++i) {
      if (id == i) continue;
      cout << id << " " << i << endl;
    }
  }
  return 0;
}

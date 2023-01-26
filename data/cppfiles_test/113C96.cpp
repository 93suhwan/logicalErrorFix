#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
char buf[100000];
inline char gc() {
  static char *st = buf, *ed = buf;
  if (st >= ed) {
    st = buf;
    ed = st + fread_unlocked(buf, 1, sizeof(buf), stdin);
    if (st == ed) return EOF;
  }
  return *(st++);
}
template <class T>
inline bool rit(T &_a) {
  char _c = gc();
  bool neg = false;
  for (; _c < '0' || _c > '9'; _c = gc()) {
    if (_c == EOF) return false;
    if (_c == '-') neg = true;
  }
  for (_a = 0; _c >= '0' && _c <= '9'; _c = gc()) _a = _a * 10 + _c - '0';
  if (neg) _a = -_a;
  return true;
}
template <class S, class... T>
inline bool rit(S &_a, T &..._b) {
  if (!rit(_a)) return false;
  return rit(_b...);
}
const int MAX_N = 0 + 10;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t, x1, p1, x2, p2;
  rit(t);
  while (t--) {
    rit(x1, p1, x2, p2);
    while (x1 && x1 % 10 == 0) x1 /= 10, p1++;
    while (x2 && x2 % 10 == 0) x2 /= 10, p2++;
    if (x1 == x2 && p1 == p2)
      cout << "=\n";
    else {
      if (int(log(x1) / log(10)) + 1 + p1 != int(log(x2) / log(10)) + 1 + p2)
        cout << (int(log(x1) / log(10)) + 1 + p1 <
                         int(log(x2) / log(10)) + 1 + p2
                     ? "<\n"
                     : ">\n");
      else
        cout << (to_string(x1) < to_string(x2) ? "<\n" : ">\n");
    }
  }
  return 0;
}

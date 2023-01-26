#include <bits/stdc++.h>
using namespace std;
template <class L, class R>
ostream &operator<<(ostream &os, map<L, R> P) {
  for (auto const &vv : P) os << "(" << vv.first << "," << vv.second << ")";
  return os;
}
template <class T>
ostream &operator<<(ostream &os, set<T> V) {
  os << "[";
  for (auto const &vv : V) os << vv << ",";
  os << "]";
  return os;
}
template <class T>
ostream &operator<<(ostream &os, vector<T> V) {
  os << "[";
  for (auto const &vv : V) os << vv << ",";
  os << "]";
  return os;
}
template <class L, class R>
ostream &operator<<(ostream &os, pair<L, R> P) {
  os << "(" << P.first << "," << P.second << ")";
  return os;
}
inline int fstoi(const string &str) {
  auto it = str.begin();
  bool neg = 0;
  int num = 0;
  if (*it == '-')
    neg = 1;
  else
    num = *it - '0';
  ++it;
  while (it < str.end()) num = num * 10 + (*it++ - '0');
  if (neg) num *= -1;
  return num;
}
inline void getch(char &x) {
  while (x = getchar_unlocked(), x < 33) {
    ;
  }
}
inline void getstr(string &str) {
  str.clear();
  char cur;
  while (cur = getchar_unlocked(), cur < 33) {
    ;
  }
  while (cur > 32) {
    str += cur;
    cur = getchar_unlocked();
  }
}
template <typename T>
inline bool sc(T &num) {
  bool neg = 0;
  int c;
  num = 0;
  while (c = getchar_unlocked(), c < 33) {
    if (c == EOF) return false;
  }
  if (c == '-') {
    neg = 1;
    c = getchar_unlocked();
  }
  for (; c > 47; c = getchar_unlocked()) num = num * 10 + c - 48;
  if (neg) num *= -1;
  return true;
}
template <typename T, typename... Args>
inline void sc(T &num, Args &...args) {
  bool neg = 0;
  int c;
  num = 0;
  while (c = getchar_unlocked(), c < 33) {
    ;
  }
  if (c == '-') {
    neg = 1;
    c = getchar_unlocked();
  }
  for (; c > 47; c = getchar_unlocked()) num = num * 10 + c - 48;
  if (neg) num *= -1;
  sc(args...);
}
int getsum(int a, int b) {
  int oor, oand;
  cout << "and " << a << ' ' << b << endl;
  cin >> oand;
  cout << "or " << a << ' ' << b << endl;
  cin >> oor;
  return oor + oand;
}
int main() {
  int n, k;
  cin >> n >> k;
  int cr;
  int x, y, z;
  x = getsum(1, 2);
  y = getsum(1, 3);
  z = getsum(2, 3);
  int a[n + 1];
  a[3] = (y + z - x) / 2;
  a[2] = (-y + z + x) / 2;
  a[1] = (y - z + x) / 2;
  for (auto i = (4); i <= (n); ++i) {
    int wh = getsum(1, i);
    a[i] = wh - a[1];
  }
  sort(a + 1, a + n + 1);
  cout << a[k] << endl;
}

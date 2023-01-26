#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline int gc() {
  static char buf[1048576], *p1 = buf, *p2 = buf;
  return (p1 == p2) &&
                 (p2 = (p1 = buf) + fread(buf, 1, 1048576, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
template <class T>
void read(T &x) {
  char c = gc();
  bool neg = false;
  while (!isdigit(c)) neg = (c == '-'), c = gc();
  x = 0;
  while (isdigit(c)) x = x * 10 + c - '0', c = gc();
  if (neg) x = -x;
}
void read(char &c) {
  for (c = ' '; isspace(c); c = gc())
    ;
}
void read(char *s) {
  char c = gc();
  while (isspace(c)) c = gc();
  while (!isspace(c)) *s++ = c, c = gc();
  *s = '\0';
}
template <typename Head, typename... Tail>
void read(Head &H, Tail &...T) {
  read(H), read(T...);
}
template <class T>
void print(T x) {
  static int buf[256], top;
  if (x < 0) x = -x, putchar(45);
  do buf[++top] = x % 10 + '0', x /= 10;
  while (x);
  while (top) putchar(buf[top--]);
}
void print(const char &c) { putchar(c); }
void print(const char *c) {
  for (int p = 0; c[p] != '\0'; print(c[p++]))
    ;
}
void print(const string &s) {
  for (int i = 0; i < (int)s.size(); print(s[i++]))
    ;
}
template <typename Head, typename... Tail>
void print(Head H, Tail... T) {
  print(H), print(T...);
}
using ull = unsigned long long;
using ll = long long;
using vi = vector<int>;
template <class T>
using v = vector<T>;
int main() {
  int tt;
  read(tt);
  while (tt--) {
    int n, m;
    read(n, m);
    vi f(n);
    iota(begin(f), end(f), 0);
    auto find = [&](int x) {
      while (x != f[x]) x = f[x] = f[f[x]];
      return x;
    };
    for (int i = 0; i < m; i++) {
      int a, b, c;
      read(a, b, c);
      print(a, ' ', c, '\n');
      --a, --c;
      f[find(a)] = find(c);
    }
    for (int i = 0; i < n; i++) {
      if (find(i) != find(0)) {
        print(i + 1, ' ', 1, '\n');
        f[find(i)] = find(0);
      }
    }
  }
  return 0;
}

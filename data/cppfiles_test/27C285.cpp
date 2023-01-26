#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  for (; !(ch >= '0' && ch <= '9'); ch = getchar())
    if (ch == '-') f *= -1;
  for (; (ch >= '0' && ch <= '9'); ch = getchar())
    x = (x << 3) + (x << 1) + (ch ^ 48);
  return x * f;
}
inline bool read(long long &x, vector<char> tl = {'\n', EOF}) {
  x = 0;
  long long f = 1;
  char ch = getchar();
  for (; !(ch >= '0' && ch <= '9'); ch = getchar())
    if (ch == '-') f *= -1;
  for (; (ch >= '0' && ch <= '9'); ch = getchar())
    x = (x << 3) + (x << 1) + (ch ^ 48);
  x *= f;
  if (ch == '\r') ch = getchar();
  return !count(tl.begin(), tl.end(), ch);
}
inline void read(char *a, vector<char> tl = {' ', '\n', '\r', '\t', '\0', EOF},
                 vector<char> skp = {' ', '\n', '\r', '\t'}) {
  char ch = getchar();
  for (; count(skp.begin(), skp.end(), ch);) ch = getchar();
  for (; !count(tl.begin(), tl.end(), ch); ch = getchar()) {
    *a = ch;
    ++a;
  }
  *a = '\0';
  return;
}
inline void read(string &a,
                 vector<char> tl = {' ', '\n', '\r', '\t', '\0', EOF},
                 vector<char> skp = {' ', '\n', '\r', '\t'}) {
  a.clear();
  char ch = getchar();
  for (; count(skp.begin(), skp.end(), ch);) ch = getchar();
  for (; !count(tl.begin(), tl.end(), ch); ch = getchar()) a += ch;
  return;
}
inline char getDg() {
  char ch = getchar();
  for (; !(ch >= '0' && ch <= '9');) ch = getchar();
  return ch;
}
inline char getLw() {
  char ch = getchar();
  for (; !(ch >= 'a' && ch <= 'z');) ch = getchar();
  return ch;
}
inline char getUp() {
  char ch = getchar();
  for (; !(ch >= 'A' && ch <= 'Z');) ch = getchar();
  return ch;
}
inline char getLtr() {
  char ch = getchar();
  for (; !((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));)
    ch = getchar();
  return ch;
}
inline char gc() {
  char ch = getchar();
  for (; ch == '\n' || ch == '\r' || ch == ' ';) ch = getchar();
  return ch;
}
inline void write(long long x) {
  if (x < 0) {
    putchar('-');
    write(-x);
    return;
  }
  if (x > 9) write(x / 10);
  putchar((x % 10) ^ 48);
  return;
}
inline void write(int x) {
  write((long long)x);
  return;
}
inline void write(char const *a) {
  for (long long i = 0; a[i]; ++i) putchar(a[i]);
  return;
}
inline void write(const string a) {
  write(a.c_str());
  return;
}
inline void write(char ch) {
  putchar(ch);
  return;
}
inline void write(pair<long long, long long> a, char const *b = " ") {
  write(a.first);
  write(b);
  write(a.second);
  return;
}
inline void clr() {
  putchar(10);
  return;
}
inline void flsh(bool nl = true) {
  if (nl) clr();
  fflush(stdout);
  return;
}
inline void spc() {
  putchar(32);
  return;
}
template <class tp>
inline void writeln(tp x) {
  write(x);
  clr();
}
inline void writeln(pair<long long, long long> a, char const *b = " ") {
  write(a, b);
  clr();
  return;
}
template <class tp>
inline void writesc(tp x) {
  write(x);
  spc();
}
inline void writesc(pair<long long, long long> a, char const *b = " ") {
  write(a);
  spc();
  return;
}
template <class tp>
inline void writeflsh(tp x, bool nl = true) {
  write(x);
  flsh(nl);
}
inline void writeflsh(pair<long long, long long> a, char const *b = " ",
                      bool nl = true) {
  write(a, b);
  flsh(nl);
  return;
}
inline void AC();
int main(int argc, char *argv[]) {
  long long tc = read();
  for (; tc--;) AC();
  return 0;
}
string a, b;
long long n, m;
inline void AC() {
  read(a);
  read(b);
  n = a.length();
  m = b.length();
  long long pa = 0, pb = 0;
  if ((n & 1) != (m & 1)) ++pa;
  for (; pb <= m - 1;) {
    if (pa >= n) {
      writeln("NO");
      return;
    }
    if (a[pa] == b[pb]) {
      ++pa;
      ++pb;
      continue;
    }
    pa += 2;
  }
  writeln("YES");
  return;
}

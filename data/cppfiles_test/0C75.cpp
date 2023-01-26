#include <bits/stdc++.h>
using namespace std;
namespace FullPre {
const int L = 1 << 15;
char buf[L], *s = buf, *t = buf;
template <typename T>
inline void read(T& x) {
  T f = 1;
  x = 0;
  int c = getchar();
  while (c < 48 || c > 57) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= 48 && c <= 57) {
    x = x * 10 + c - '0';
    c = getchar();
  }
  x *= f;
}
template <typename T, typename... args>
inline void read(T& x, args&... Args) {
  read(x), read(Args...);
}
template <typename T>
inline void write(T x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
template <typename T>
inline void print_char(T x, char ch) {
  write(x), putchar(ch);
}
template <typename T>
inline void char_print(char ch, T x) {
  putchar(ch), write(x);
}
template <typename T>
inline void print_space(T x) {
  print_char(x, ' ');
}
template <typename T>
inline void print_space_mul(T x) {
  print_space(x);
}
template <typename T, typename... args>
inline void print_space_mul(T x, args... Args) {
  print_space(x), print_space_mul(Args...);
}
template <typename T>
inline void space_print(T x) {
  char_print(' ', x);
}
template <typename T>
inline void space_print_mul(T x) {
  space_print(x);
}
template <typename T, typename... args>
inline void space_print_mul(T x, args... Args) {
  space_print(x), space_print_mul(Args...);
}
template <typename T>
inline void println(T x) {
  print_char(x, '\n');
}
template <typename T>
inline void println_mul(T x) {
  println(x);
}
template <typename T, typename... args>
inline void println_mul(T x, args... Args) {
  println(x), println_mul(Args...);
}
template <typename T>
inline void lnprint(T x) {
  char_print('\n', x);
}
template <typename T>
inline void lnprint_mul(T x) {
  lnprint(x);
}
template <typename T, typename... args>
inline void lnprint_mul(T x, args... Args) {
  lnprint(x), lnprint_mul(Args...);
}
inline void filein(string s) { freopen((s + ".in").c_str(), "r", stdin); }
inline void fileout(string s) { freopen((s + ".out").c_str(), "w", stdout); }
inline void file(string s) { filein(s), fileout(s); }
template <typename T>
inline T mymin(T a, T b) {
  return a < b ? a : b;
}
template <typename T, typename... args>
inline T mymin(T a, T b, args... Args) {
  return mymin(mymin(a, b), Args...);
}
template <typename T>
inline T mymax(T a, T b) {
  return a > b ? a : b;
}
template <typename T, typename... args>
inline T mymax(T a, T b, args... Args) {
  return mymax(mymax(a, b), Args...);
}
template <typename T>
inline T myabs(T a) {
  return a < 0 ? -a : a;
}
template <typename T>
inline T mysq(T a) {
  return a * a;
}
template <typename T>
inline T mygcd(T a, T b) {
  return !b ? a : mygcd(b, a % b);
}
template <typename T, typename... args>
inline T mygcd(T a, T b, args... Args) {
  return mygcd(mygcd(a, b), Args...);
}
template <typename T>
inline T mylcm(T a, T b) {
  return a / mygcd(a, b) * b;
}
template <typename T, typename... args>
inline T mylcm(T a, T b, args... Args) {
  return mylcm(mylcm(a, b), Args...);
}
template <typename T>
inline T myswap(T& a, T& b) {
  a ^= b ^= a ^= b;
}
}  // namespace FullPre
using namespace FullPre;
namespace Solution {
struct node {
  string str;
  int id;
  bool operator<(const node& t) const { return str < t.str; }
} a[1000007];
inline void Main() {
  int n, m;
  read(n, m);
  for (int(i) = (1); (i) <= (n); ++(i)) {
    cin >> a[i].str;
    a[i].id = i, a[i].str = " " + a[i].str;
    for (int(j) = (2); (j) <= (m); (j) += (2))
      a[i].str[j] = 'Z' - a[i].str[j] + 'A';
  }
  sort(a + 1, a + n + 1);
  for (int(i) = (1); (i) <= (n); ++(i)) printf("%d%c", a[i].id, " \n"[i == n]);
  return;
}
}  // namespace Solution
int main() {
  Solution ::Main();
  return 0;
}

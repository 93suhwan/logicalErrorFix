#include <bits/stdc++.h>
using namespace std;
namespace FullPre {
template <typename T>
inline void read(T &x) {
  T f = 1;
  x = 0;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = x * 10 + c - '0';
    c = getchar();
  }
  x *= f;
}
template <typename T, typename... args>
inline void read(T &x, args &...Args) {
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
inline T myswap(T &a, T &b) {
  a ^= b ^= a ^= b;
}
}  // namespace FullPre
using namespace FullPre;
namespace Solution {
const long long N = 17;
long long n, k, a[N], pw[N];
inline void Main() {
  pw[0] = 1;
  for (long long(i) = (1); (i) <= (14); ++(i)) pw[i] = pw[i - 1] * 10;
  long long Test;
  read(Test);
  while (Test--) {
    read(n, k);
    for (long long(i) = (1); (i) <= (n); ++(i)) read(a[i]);
    long long sum = 0;
    bool fl = 0;
    string ans = "";
    for (long long(i) = (1); (i) <= (n - 1); ++(i)) {
      if (sum + pw[a[i + 1] - a[i]] - 1 <= k) {
        sum += pw[a[i + 1] - a[i]] - 1;
        for (long long(j) = (a[i]); (j) <= (a[i + 1] - 1); ++(j)) ans += "9";
        continue;
      }
      fl = 1;
      write(k - sum + 1), cout << ans << endl;
      break;
    }
    if (fl) continue;
    write(k - sum + 1), cout << ans << endl;
  }
  return;
}
}  // namespace Solution
int main() {
  Solution ::Main();
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T& t) {
  T sum = 0, f = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) sum = sum * 10 + c - '0', c = getchar();
  t = sum * f;
}
inline void read(double& r) {
  double x = 0, t = 0;
  int s = 0, f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar()) {
    if (c == '-') f = -1;
    if (c == '.') goto readt;
  }
  for (; isdigit(c) && c != '.'; c = getchar()) x = x * 10 + c - '0';
readt:
  for (; c == '.'; c = getchar())
    ;
  for (; isdigit(c); c = getchar()) t = t * 10 + c - '0', ++s;
  r = (x + t / pow(10, s)) * f;
}
inline void read(string& x) {
  x = "";
  char ch = getchar();
  while (ch == ' ' || ch == '\n' || ch == '\r') ch = getchar();
  while (ch != ' ' && ch != '\n' && ch != '\r') x += ch, ch = getchar();
}
template <typename T, typename... Args>
inline void read(T& t, Args&... args) {
  read(t);
  read(args...);
}
template <typename T>
inline void write(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
inline void write(double x, int k = 6) {
  static int n = pow(10, k + 1);
  if (x == 0) {
    putchar('0'), putchar('.');
    for (int i = 1; i <= k; ++i) putchar('0');
    return;
  }
  if (x < 0) putchar('-'), x = -x;
  long long y = (long long)(x * n) % n;
  x = (long long)x;
  write((long long)x), putchar('.');
  int bit[10], p = 0, i;
  if (y % 10 >= 5)
    y = y / 10 + 1;
  else
    y = y / 10;
  for (; p < k; y /= 10) bit[++p] = y % 10;
  for (i = p; i > 0; i--) putchar(bit[i] + 48);
}
inline void write(string x) {
  for (int i = 0; x[i] != '\0'; i++) putchar(x[i]);
}
template <typename T>
inline void write(const char ch, T x) {
  write(x);
  putchar(ch);
}
template <typename T, typename... Args>
inline void write(const char ch, T x, Args... args) {
  write(ch, x);
  write(ch, args...);
}
const int mod = 1e9 + 7;
const int Count = 10;
const int N = 2e5 + 5;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5;
const int charSum = 26;
const double pi = acos(-1);
const double eps = 1e-6;
const int NTT_mod = 998244353;
signed main(void) {
  int t;
  read(t);
  while (t--) {
    int n;
    read(n);
    string a, b;
    read(a, b);
    int num1 = 0, num0 = 0, num = 0;
    int numy1 = 0, numy0 = 0;
    int len = a.length();
    for (int i = 0; i < len; i++) {
      if (a[i] != b[i]) {
        if (a[i] == '1')
          num1++;
        else
          num0++;
        num++;
      } else {
        if (a[i] == '1')
          numy1++;
        else
          numy0++;
      }
    }
    int ans = 100005;
    numy1--;
    int temp = numy0;
    numy0 = numy1;
    numy1 = temp;
    if (num0 == num1) {
      ans = min(ans, num0 + num1);
    }
    if (numy0 == numy1) {
      ans = min(ans, numy0 + numy1 + 1);
    }
    write('\n', ans == 100005 ? -1 : ans);
  }
  return 0;
}

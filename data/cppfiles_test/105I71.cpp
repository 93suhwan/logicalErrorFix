#include <bits/stdc++.h>
using namespace std;
template <typename S, typename T>
bool chminx(S &a, const T &b) {
  return a < b ? 1 : a = b, 0;
}
template <typename S, typename T>
bool chmaxx(S &a, const T &b) {
  return a > b ? 1 : a = b, 0;
}
template <typename T>
void read_int(T &res) {
  int flag = 1;
  char ch;
  while (isspace(ch = getchar()))
    ;
  res = 0;
  if (ch == '-')
    flag = -1;
  else if (ch >= '0' && ch <= '9')
    res = ch - '0';
  while ((ch = getchar()) >= '0' && ch <= '9') res = res * 10 + ch - '0';
  res *= flag;
}
template <typename T, typename... Args>
void read_ints(T &t, Args &...args) {
  read_int(t);
  read_int(args...);
}
template <typename T>
void int_out(T a) {
  if (a < 0) {
    putchar('-');
    a = -a;
  }
  if (a > 9) int_out(a / 10);
  putchar(a % 10 + '0');
}
const int INF = 0x3f3f3f3f;
const double tol = 1e-8;
const int N = 1000006;
int a[N], b[N], m[N];
int main() {
  int t;
  read_int(t);
  while (t--) {
    int n;
    read_int(n);
    long long minsum = 0, maxsum = 0, tot = 0;
    for (int i = 1; i <= n; ++i) {
      read_ints(a[i], b[i]);
      read_int(m[i]);
      tot += a[i] + b[i] - m[i];
      minsum += a[i] > m[i] ? a[i] - m[i] : 0;
      maxsum += b[i] >= m[i] ? a[i] : a[i] - (m[i] - b[i]);
    }
    minsum *= 2;
    maxsum *= 2;
    if (minsum >= tot) {
      int_out(minsum - tot);
      puts("");
      for (int i = 1; i <= n; ++i) {
        if (a[i] >= m[i]) {
          a[i] = m[i];
          b[i] = 0;
        } else {
          b[i] = (m[i] - a[i]);
        }
      }
    } else if (tot >= maxsum) {
      int_out(tot - maxsum);
      puts("");
      for (int i = 1; i <= n; ++i) {
        if (b[i] >= m[i]) {
          b[i] = m[i];
          a[i] = 0;
        } else {
          a[i] = (m[i] - b[i]);
        }
      }
    } else {
      int_out(tot & 1);
      puts("");
      tot = (tot - minsum) / 2;
      for (int i = 1; i <= n; ++i) {
        if (tot == 0) {
          if (a[i] >= m[i]) {
            a[i] = m[i];
            b[i] = 0;
          } else {
            b[i] = m[i] - a[i];
          }
          continue;
        }
        int maxval = a[i] >= m[i] ? m[i] : a[i];
        int minval = b[i] >= m[i] ? 0 : (m[i] - b[i]);
        if (maxval - tot >= minval) {
          a[i] = maxval - tot;
          b[i] = m[i] - a[i];
          tot = 0;
        } else {
          a[i] = minval;
          b[i] = m[i] - minval;
          tot -= maxval - minval;
        }
      }
    }
    for (int i = 1; i <= n; ++i) {
      int_out(a[i]);
      putchar(' ');
      int_out(b[i]);
      puts("");
    }
  }
  return 0;
}

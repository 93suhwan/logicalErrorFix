#include <bits/stdc++.h>
using namespace std;
template <typename S, typename T>
bool minx(S &a, const T &b) {
  return a < b ? 1 : a = b, 0;
}
template <typename T>
void int_in(T &res) {
  int flag = 1;
  char ch;
  if ((ch = getchar()) == '-')
    flag = -1;
  else if (ch >= '0' && ch <= '9')
    res = ch - '0';
  while ((ch = getchar()) >= '0' && ch <= '9') res = res * 10 + ch - '0';
  res *= flag;
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
const int N = 100005;
int a[N];
int main() {
  int t;
  int_in(t);
  while (t--) {
    int n;
    int_in(n);
    for (int i = 1; i <= n; ++i) {
      int_in(a[i]);
    }
    if (n & 1) {
      if (a[1] + a[2] != 0) {
        printf("%d %d %d ", a[3], a[3], -(a[1] + a[2]));
      } else if (a[1] + a[3] != 0) {
        printf("%d %d %d ", a[2], -(a[1] + a[3]), a[2]);
      } else {
        printf("%d %d %d ", -(a[2] + a[3]), a[1], a[1]);
      }
    }
    for (int i = 1 + 3 * (n & 1); i <= n; i += 2) {
      int_out(-a[i + 1]);
      putchar(' ');
      int_out(a[i]);
      putchar(' ');
    }
    puts("");
  }
  return 0;
}

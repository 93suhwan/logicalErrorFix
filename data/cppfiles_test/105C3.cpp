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
int a[N], b[N], m[N], p[N], c[N], d[N];
int main() {
  int t;
  read_int(t);
  while (t--) {
    int n;
    read_int(n);
    for (int i = 1; i <= n; ++i) {
      read_ints(a[i], b[i]);
      read_int(m[i]);
      c[i] = a[i] >= m[i] ? a[i] - m[i] : 0;
      d[i] = b[i] >= m[i] ? a[i] : a[i] - (m[i] - b[i]);
      p[i] = i;
    }
    sort(p + 1, p + 1 + n, [&](const int idx1, const int idx2) {
      if (a[idx1] + b[idx1] - m[idx1] != a[idx2] + b[idx2] - m[idx2])
        return a[idx1] + b[idx1] - m[idx1] < a[idx2] + b[idx2] - m[idx2];
      return d[idx1] < d[idx2];
    });
    int ans = 0;
    for (int i = 1, j; i <= n; i = j) {
      ++ans;
      int u = p[i];
      for (j = i + 1; j <= n; ++j) {
        int v = p[j];
        if (a[u] + b[u] - m[u] != a[v] + b[v] - m[v]) break;
      }
      a[u] -= d[u];
      b[u] = m[u] - a[u];
      int pa = d[u];
      for (int k = i + 1; k <= j - 1; ++k) {
        int x = p[k];
        if (c[x] > pa) {
          ++ans;
          a[x] -= d[x];
          b[x] = m[x] - a[x];
          pa = d[x];
        } else {
          a[x] -= pa;
          b[x] = m[x] - a[x];
        }
      }
    }
    int_out(ans);
    puts("");
    for (int i = 1; i <= n; ++i) {
      int_out(a[i]);
      putchar(' ');
      int_out(b[i]);
      puts("");
    }
  }
  return 0;
}

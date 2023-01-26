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
const int N = 1 << 13;
vector<int> g[N];
int ans[N], r[N];
int main() {
  int n;
  int_in(n);
  for (int i = 0; i <= N - 1; ++i) {
    r[i] = N;
    g[i].push_back(0);
  }
  ans[0] = 1;
  for (int i = 1; i <= n; ++i) {
    int u;
    int_in(u);
    for (auto &v : g[u]) {
      int x = u ^ v;
      ans[x] = 1;
      if (r[x] > u) r[x]--;
      while (r[x] > u) {
        g[r[x]].push_back(x);
        r[x]--;
      }
    }
    g[u].clear();
  }
  int_out(accumulate(ans, ans + N, 0)), puts("");
  for (int i = 0; i <= N - 1; ++i) {
    if (ans[i]) int_out(i), putchar(' ');
  }
  puts("");
  return 0;
}

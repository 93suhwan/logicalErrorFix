#include <bits/stdc++.h>
namespace FastRead {
char __buff[5000];
int __lg = 0, __p = 0;
char nc() {
  if (__lg == __p) {
    __lg = fread(__buff, 1, 5000, stdin);
    __p = 0;
    if (!__lg) return EOF;
  }
  return __buff[__p++];
}
template <class T>
void read(T& __x) {
  T __sgn = 1;
  char __c;
  while (!isdigit(__c = nc()))
    if (__c == '-') __sgn = -1;
  __x = __c - '0';
  while (isdigit(__c = nc())) __x = __x * 10 + __c - '0';
  __x *= __sgn;
}
}  // namespace FastRead
using namespace FastRead;
using namespace std;
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const long double PI = acos(-1);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n;
int a[N], d[N][500];
void Test() {
  int i, k;
  cin >> n;
  for (i = 1; i <= n; i++)
    cin >> a[i], a[i] += a[i - 1], d[i][1] = a[i] - a[i - 1];
  for (i = n - 1; i >= 1; i--) d[i][1] = max(d[i][1], d[i + 1][1]);
  for (k = 2; k * (k + 1) / 2 <= n; k++)
    for (i = n; i >= 1; i--) {
      d[i][k] = 0;
      if (i + k * (k + 1) / 2 - 1 <= n) {
        d[i][k] = d[i + 1][k];
        if (d[i + k][k - 1] && a[i + k - 1] - a[i - 1] < d[i + k][k - 1])
          d[i][k] = max(d[i][k], a[i + k - 1] - a[i - 1]);
      }
      d[i][k] = max(d[i][k], d[i + 1][k]);
    }
  int ans = 0;
  for (k = 1; k * (k + 1) / 2 <= n; k++)
    for (i = 1; i + k - 1 <= n; i++)
      if (d[i][k]) ans = max(ans, k);
  cout << ans << '\n';
  for (k = 1; k < 500; k++)
    for (i = 1; i <= n; i++) d[i][k] = 0;
}
signed main() {
  int q;
  cin >> q;
  while (q--) Test();
  return 0;
}

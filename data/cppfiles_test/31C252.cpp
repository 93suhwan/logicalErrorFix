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
int a[N], b[N];
void Test() {
  int i;
  cin >> n;
  for (i = 1; i <= n; i++) cin >> a[i];
  for (i = 1; i <= n; i += 2) {
    b[i] = a[i + 1];
    b[i + 1] = a[i];
    b[i + 1] *= -1;
  }
  if (n & 1) {
    b[n - 1] = b[n - 2] = a[n];
    b[n] = a[n - 1] + a[n - 2];
    if (!b[n]) {
      b[n - 1] *= 2;
      b[n] = 2 * a[n - 1] + a[n - 2];
    }
    b[n] *= -1;
  }
  for (i = 1; i <= n; i++) cout << b[i] << ' ';
  cout << '\n';
}
signed main() {
  int q;
  cin >> q;
  while (q--) Test();
  return 0;
}

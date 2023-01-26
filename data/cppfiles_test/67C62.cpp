#include <bits/stdc++.h>
using namespace std;
template <class T>
void read(T& x) {
  x = 0;
  T f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') f = (ch == '-' ? -1 : 1), ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = getchar();
  x *= f;
}
template <class T, class... Args>
void read(T& x, Args&... args) {
  read(x), read(args...);
}
template <class T>
void write(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
const int MAXN = 2E5 + 5;
const int MOD = 1E9 + 7;
long long n, num;
double p;
bool check(long long k) {
  return (-k * k * k + 3 * k * k + k * (4 + 3 * n * n - 9 * n)) * 10000 >=
         num * n * (n - 1) * (n - 2) * 2;
}
signed main() {
  cin >> n >> p;
  num = llround(p * 10000);
  int l = 0, r = n, ans = 0;
  while (l <= r) {
    int mid = l + r >> 1;
    if (check(mid)) {
      ans = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  cout << ans;
  return 0;
}

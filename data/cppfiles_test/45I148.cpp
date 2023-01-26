#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e6 + 10;
inline void write(int x) {
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
  return;
}
inline long long Read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
long long T, n, ans;
long long a[maxn];
void work() {
  for (int i = n; i >= 2; --i) {
    if (a[i] % 2 + a[i - 1] % 2 != 1) {
      for (int j = i - 2; j >= 1; --j) {
        if (a[i - 1] % 2 != a[j] % 2) {
          ans += i - j - 1;
          long long tmp = a[j];
          for (int k = j; k <= i - 2; ++k) a[k] = a[k + 1];
          a[i - 1] = tmp;
          break;
        }
      }
    }
  }
  for (int i = 1; i <= n - 1; ++i) {
    if (a[i] % 2 + a[i + 1] % 2 != 1) {
      for (int j = i + 2; j <= n; ++j) {
        if (a[i + 1] % 2 != a[j] % 2) {
          ans += j - i - 1;
          long long tmp = a[j];
          for (int k = j; k >= i + 2; --k) a[k] = a[k - 1];
          a[i + 1] = tmp;
          break;
        }
      }
    }
  }
  for (int i = 1; i <= n - 1; ++i)
    if (a[i] % 2 + a[i + 1] % 2 != 1) {
      ans = -1;
      return;
    }
}
int main() {
  T = Read();
  while (T--) {
    n = Read();
    ans = 0;
    for (int i = 1; i <= n; ++i) a[i] = Read();
    work();
    cout << ans << '\n';
  }
  return 0;
}

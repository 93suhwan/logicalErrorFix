#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
inline void write(int x) {
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
  return;
}
inline int Read() {
  int x = 0, f = 1;
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
int T, n, odd, even, ans;
int a[maxn];
void work() {
  for (int i = 1; i <= n - 1; ++i) {
    if (a[i] % 2 + a[i + 1] % 2 != 1) {
      for (int j = i + 1; j <= n; ++j) {
        if (a[i + 1] % 2 != a[j] % 2) {
          swap(a[i + 1], a[j]);
          ans += j - i - 1;
          break;
        }
      }
    }
  }
}
int main() {
  T = Read();
  while (T--) {
    n = Read();
    odd = 0;
    even = 0;
    ans = 0;
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      if (a[i] % 2)
        odd++;
      else
        even++;
    }
    if (n == 1) {
      cout << 0 << '\n';
      continue;
    }
    if (n % 2 == 0 && odd != even) {
      cout << -1 << '\n';
      continue;
    }
    if (n % 2 != 0 && abs(odd - even) != 1) {
      cout << -1 << '\n';
      continue;
    }
    work();
    cout << ans << '\n';
  }
  return 0;
}

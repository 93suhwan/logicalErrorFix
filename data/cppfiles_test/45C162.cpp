#include <bits/stdc++.h>
using namespace std;
const int N = 5e6 + 10;
long long a[N], n;
bool is[N];
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
void work() {
  long long ans = 1e18;
  int e = 0, o = 0;
  n = Read();
  for (int i = 1; i <= n; ++i) {
    a[i] = Read();
    if (a[i] % 2 == 0)
      e++, is[i] = 0;
    else
      o++, is[i] = 1;
  }
  if (n % 2 == 0) {
    if (o != e)
      puts("-1");
    else {
      long long c1 = 0, c0 = 0;
      for (int i = 1, j = 1, k = 1; i <= n; ++i) {
        if (is[i] == 1) {
          c1 += abs(i - j);
          j += 2;
        } else {
          c0 += abs(i - k);
          k += 2;
        }
      }
      ans = min(min(ans, c0), c1);
      cout << ans << '\n';
    }
  } else {
    if (o == n / 2 && e == n / 2 + 1) {
      long long c = 0;
      for (int i = 1, j = 1; i <= n; ++i) {
        if (is[i] == 0) {
          c += abs(i - j);
          j += 2;
        }
      }
      ans = min(ans, c);
      cout << ans << '\n';
    } else if (e == n / 2 && o == n / 2 + 1) {
      long long c = 0;
      for (int i = 1, j = 1; i <= n; ++i) {
        if (is[i] == 1) {
          c += abs(i - j);
          j += 2;
        }
      }
      ans = min(ans, c);
      cout << ans << '\n';
    } else
      puts("-1");
  }
}
int main() {
  int T;
  cin >> T;
  while (T--) work();
  return 0;
}

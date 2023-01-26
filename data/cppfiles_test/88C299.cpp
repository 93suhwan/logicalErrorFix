#include <bits/stdc++.h>
using namespace std;
inline int read() {
  bool ok = 0;
  int res = 0;
  char c;
  while (((c = getchar()) < '0' || c > '9') && c != '-')
    ;
  if (c == '-')
    ok = 1;
  else
    res = c - 48;
  while ((c = getchar()) >= '0' && c <= '9')
    res = (res << 3) + (res << 1) + (c - 48);
  return ok ? ~res + 1 : res;
}
int t, n, m, k, x, y, len;
int a[100010];
int main() {
  t = read();
  while (t--) {
    n = read();
    for (int i = 1; i <= n; ++i) a[i] = read();
    if (n % 2 == 0)
      cout << "YES\n";
    else {
      int ok = 0;
      for (int i = 2; i <= n; ++i) {
        if (a[i] <= a[i - 1]) {
          ok = 1;
          break;
        }
      }
      if (ok)
        cout << "YES\n";
      else
        cout << "NO\n";
    }
  }
  return 0;
}

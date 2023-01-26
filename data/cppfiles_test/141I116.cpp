#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  return x * f;
}
const long long inf = 924923324;
const long long maxn = 2e5 + 100;
const long long mode = 998244353;
long long t, n, m, si[maxn], a, s;
char x[44], y[55];
signed main() {
  t = read();
  while (t--) {
    scanf("%s", x + 1);
    scanf("%s", y + 1);
    a = 0;
    s = 0;
    long long l = strlen(x + 1);
    long long r = strlen(y + 1);
    for (long long i = l; i >= 1; --i) a = a * 10 + x[i] - '0';
    for (long long i = r; i >= 1; --i) s = s * 10 + y[i] - '0';
    if (a == s)
      cout << 0 << "\n";
    else if (a > s)
      cout << -1 << "\n";
    else {
      long long base = 1;
      long long cur = r;
      long long ans = 0;
      bool juge = true;
      for (long long i = l; i >= 1; --i) {
        long long tl = x[i] - '0';
        long long tr = y[cur] - '0';
        long long dis = tr - tl;
        if (dis < 0) {
          dis += 10;
          if (cur == 1 || y[cur - 1] != '1') {
            juge = false;
            break;
          }
          cur--;
          ans = ans + dis * base;
        } else {
          ans = ans + dis * base;
        }
        cur--;
        base *= 10;
      }
      if (juge && cur != 0) {
        for (long long i = cur; i >= 1; --i) {
          ans = ans + (y[i] - '0') * base;
          base *= 10;
        }
      }
      if (juge)
        cout << ans << "\n";
      else
        cout << -1 << "\n";
    }
  }
}

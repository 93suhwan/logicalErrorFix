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
const long long maxn = 2e5 + 1000;
long long t, n, m, a, b, si[maxn];
signed main() {
  t = read();
  while (t--) {
    n = read();
    a = read();
    b = read();
    long long dis = abs(a - b);
    if (a + b + 2 > n || dis > 1)
      cout << -1 << "\n";
    else {
      if (a > b) {
        for (long long i = 1; i <= a; ++i) cout << i << ' ' << n - i + 1 << ' ';
        long long l = a + 1, r = n + 1 - l;
        for (long long i = r; i >= l; --i) cout << i << ' ';
        cout << "\n";
      } else if (a == b) {
        for (long long i = 1; i <= a; ++i) cout << i << ' ' << n - i + 1 << ' ';
        long long l = a + 1, r = n + 1 - l;
        for (long long i = l; i <= r; ++i) cout << i << ' ';
        cout << "\n";
      } else {
        for (long long i = 1; i <= b; ++i) cout << n - i + 1 << ' ' << i << ' ';
        long long l = b + 1, r = n + 1 - l;
        for (long long i = l; i <= r; ++i) cout << i << ' ';
        cout << "\n";
      }
    }
  }
}

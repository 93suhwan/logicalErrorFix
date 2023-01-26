#include <bits/stdc++.h>
namespace infinities {
const long long maxn = 1e6 + 7;
const long long INF = 1e9 + 7;
using namespace std;
long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
long long t, n, a, b, p[maxn];
void print() {
  for (register long long i = 1; i <= n; i++) cout << p[i] << " ";
  cout << "\n";
}
signed main() {
  t = read();
  while (t--) {
    n = read(), a = read(), b = read();
    if (abs(a - b) >= 2) {
      cout << "-1\n";
      continue;
    }
    register long long cnt = 0;
    if (a > b) {
      for (register long long i = 1; i <= b + 1; i++) {
        p[++cnt] = n - a * 2 + i, p[++cnt] = n - a * 2 + i + b + 1;
      }
      if (n - cnt < 1) {
        puts("-1");
        continue;
      }
      for (register long long i = cnt + 1; i <= n; i++) p[i] = n - i + 1;
      print();
      continue;
    }
    if (a < b) {
      for (register long long i = 1; i <= a + 1; i++) {
        p[++cnt] = i + b, p[++cnt] = i;
      }
      if (n - cnt < 1) {
        puts("-1");
        continue;
      }
      for (register long long i = cnt + 1; i <= n; i++) p[i] = i;
      print();
      continue;
    }
    if (a == b) {
      for (register long long i = 1; i <= a + 1; i++)
        p[++cnt] = i, p[++cnt] = i + b + 1;
      if (n - cnt < 0) {
        puts("-1");
        continue;
      }
      for (register long long i = cnt + 1; i <= n; i++) p[++cnt] = i;
      print();
      continue;
    }
  }
  return 0;
}
}  // namespace infinities
signed main() { return infinities::main(); }

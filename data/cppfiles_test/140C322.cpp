#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
const long long inf = 0x3f3f3f3f;
const long long mod = 1e9 + 7;
long long n, m, k, a[N], b[N], c[N], y, ans, sum, l, r;
template <typename T>
void inline read(T &x) {
  long long f = 1;
  x = 0;
  char s = getchar();
  while (s<'0' | s> '9') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s <= '9' && s >= '0')
    x = (x << 3) + (x << 1) + (s ^ 48), s = getchar();
  x *= f;
}
string s;
void init() {
  for (long long i = 1; i <= 100000; i++) {
    a[i] = i * i * i;
    b[i] = i * i;
  }
  for (long long i = 1; i <= 100000; i++) {
    if ((long long)sqrt(a[i]) * (long long)sqrt(a[i]) == a[i]) {
      c[y] = a[i];
      y++;
    }
  }
}
inline void run() {
  long long n;
  read(n);
  long long a = sqrt(n), b = pow(n, 1 / 3.0);
  long long c = pow(n, 1 / 6.0);
  while ((b + 1) * (b + 1) * (b + 1) <= n) b++;
  while ((c + 1) * (c + 1) * (c + 1) * (c + 1) * (c + 1) * (c + 1) <= n) c++;
  printf("%d\n", a + b - c);
}
signed main() {
  long long T;
  init();
  for (cin >> T; T > 0; T--) run();
  return 0;
}

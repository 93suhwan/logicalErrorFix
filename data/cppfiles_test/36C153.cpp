#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
inline int read() {
  int s = 0, w = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    s = s * 10 + ch - '0';
    ch = getchar();
  }
  return s * w;
}
int n;
int a[N];
void solve() {
  n = read();
  int sum = 0;
  for (int i = 1; i <= n; i++) a[i] = read(), sum += a[i];
  for (int i = 2; i * i <= sum; i++) {
    if (sum % i == 0) {
      printf("%d\n", n);
      for (int i = 1; i <= n; i++) printf("%d ", i);
      puts("");
      return;
    }
  }
  printf("%d\n", n - 1);
  bool ok = 0;
  for (int i = 1; i <= n; i++) {
    if (!ok && a[i] % 2 == 1) {
      ok = 1;
      continue;
    }
    printf("%d ", i);
  }
  puts("");
}
int main() {
  int T = read();
  while (T--) solve();
  return 0;
}

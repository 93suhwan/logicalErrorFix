#include <bits/stdc++.h>
using namespace std;
const int N = 65;
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
  for (int i = 1; i <= n; i++) a[i] = read();
  if (n % 2 == 0) {
    for (int i = 1; i < n; i += 2) {
      printf("%d %d ", a[i + 1], -a[i]);
    }
    puts("");
  } else {
    printf("%d %d %d ", a[3], a[3], -a[1] - a[2]);
    for (int i = 4; i < n; i += 2) printf("%d %d ", a[i + 1], -a[i]);
    puts("");
  }
}
int main() {
  int T = read();
  while (T--) solve();
  return 0;
}

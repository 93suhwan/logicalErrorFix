#include <bits/stdc++.h>
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
using namespace std;
inline int read() {
  char ch = getchar();
  int s = 0, w = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    s = s * 10 + ch - '0', ch = getchar();
  }
  return s * w;
}
const int N = 1e6 + 9;
int n;
int a[N];
int check() {
  for (int i = 1; i < n; i++) {
    if (a[i] > a[i + 1]) return 0;
  }
  return 1;
}
signed main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int a, b;
    scanf("%d%d", &a, &b);
    if (a < b) swap(a, b);
    int f = 0;
    if (a == b) f = 1;
    int k = a - b;
    k = k / 2;
    int t = min(a, b);
    int he = a + b;
    int kk = he - t * 2;
    kk = (kk + 1) / 2 + t * 2;
    int tt = kk - k + 1;
    if (f) tt = (tt + 1) / 2;
    printf("%d\n", tt);
    for (int i = k; i <= kk; i++) {
      if (f && (i & 1)) continue;
      printf("%d%c", i, i == kk ? '\n' : ' ');
    }
  }
  return 0;
}

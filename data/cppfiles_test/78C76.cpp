#include <bits/stdc++.h>
using namespace std;
char buf[100000], *p1 = buf, *p2 = buf;
inline int gi() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return (f == 1) ? x : -x;
}
const int maxn = 2e5 + 5;
int cnt[maxn];
int n, a[maxn];
inline void init() {
  for (int i = 0; i <= 30; ++i) cnt[i] = 0;
}
inline void input() {
  n = gi();
  for (int i = 1; i <= n; ++i) a[i] = gi();
  for (int i = 0; i <= 29; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (a[j] >> i & 1) cnt[i]++;
    }
  }
}
inline void solve() {
  for (int i = 1; i <= n; ++i) {
    bool ok = 1;
    for (int j = 0; j <= 29; ++j) {
      if (cnt[j] % i != 0) ok = 0;
    }
    if (ok) printf("%d ", i);
  }
  puts("");
}
int main() {
  int T = gi();
  while (T--) {
    init();
    input();
    solve();
  }
  return 0;
}

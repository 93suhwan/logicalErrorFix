#include <bits/stdc++.h>
using namespace std;
inline long long rd() {
  char c = getchar();
  long long s = 0;
  bool f = 1;
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') f = 0;
  for (; c >= '0' && c <= '9'; c = getchar())
    s = (s << 3) + (s << 1) + (c ^ 48);
  return f ? s : ~(s - 1);
}
inline void wt(long long x) { printf("%lld", x); }
inline void wtl(long long x) { printf("%lld\n", x); }
inline void wtb(long long x) { printf("%lld ", x); }
const int N = 5e5 + 10, mod = 1e9 + 7;
int n, a[N], b[N];
int cnt[N];
inline void work() {
  n = rd();
  memset(cnt + 1, 0, n << 2);
  for (int i = 1; i <= n; ++i) a[i] = rd(), ++cnt[a[i]], b[i] = a[i];
  bool flag = 1;
  for (int i = 1; i < n; ++i) {
    if (a[i] > a[i + 1]) {
      flag = 0;
      break;
    }
  }
  if (flag) {
    puts("YES");
    return;
  }
  if (n == 2) {
    puts("NO");
    return;
  }
  sort(b + 1, b + 1 + n);
  int c = 0;
  for (int i = 1; i <= n; ++i)
    if (a[i] != b[i]) ++c;
  if (c > 2) {
    puts("YES");
    return;
  }
  int d[5], h = 0;
  for (int i = 1; i <= n; ++i)
    if (a[i] != b[i]) d[++h] = a[i];
  if (cnt[d[1]] + cnt[d[2]] >= 3) {
    puts("YES");
  } else
    puts("NO");
}
int main() {
  int T = 1;
  T = rd();
  for (int i = 1; i <= T; ++i) {
    work();
  }
  return 0;
}

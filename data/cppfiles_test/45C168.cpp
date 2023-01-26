#include <bits/stdc++.h>
using namespace std;
inline void rd(char *x) { scanf("%s", x); }
inline void rd(double &x) { scanf("%lf", &x); }
template <typename T>
inline void rd(T &x) {
  x = 0;
  char ch = getchar();
  while (!isdigit(ch)) ch = getchar();
  while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
}
template <typename T, typename... U>
inline void rd(T &x, U &...y) {
  rd(x), rd(y...);
}
template <typename T>
inline void write(T x) {
  if (x >= 10) write(x / 10);
  putchar('0' + x % 10);
}
const int maxn = 114514;
int a[maxn], n;
int t[maxn];
inline int lb(int x) { return x & (-x); }
inline void upd(int x, int val) {
  for (; x <= n; x += lb(x)) t[x] += val;
}
inline int ask(int x) {
  int ret = 0;
  for (; x; x -= lb(x)) ret += t[x];
  return ret;
}
long long check() {
  int id0 = -1, id1 = 0;
  long long ans = 0;
  fill_n(t, n + 2, 0);
  for (int i = (1), __i = (n); i <= __i; ++i) {
    if (a[i]) {
      id1 += 2;
      ans += ask(n) - ask(id1);
      upd(id1, 1);
    } else {
      id0 += 2;
      ans += ask(n) - ask(id0);
      upd(id0, 1);
    }
  }
  return ans;
}
int main() {
  int T;
  rd(T);
  for (int kase = (1), __kase = (T); kase <= __kase; ++kase) {
    rd(n);
    for (int i = (1), __i = (n); i <= __i; ++i) rd(a[i]);
    int cnt = 0;
    for (int i = (1), __i = (n); i <= __i; ++i)
      if (a[i] %= 2) ++cnt;
    int cnt0 = n - cnt;
    if (abs(cnt0 - cnt) > 1) {
      puts("-1");
      continue;
    }
    long long ans = 1ll << 59;
    if (cnt0 >= cnt) ans = check();
    if (cnt >= cnt0) {
      for (int i = (1), __i = (n); i <= __i; ++i) a[i] ^= 1;
      ans = min(ans, check());
    }
    printf("%lld\n", ans);
  }
}

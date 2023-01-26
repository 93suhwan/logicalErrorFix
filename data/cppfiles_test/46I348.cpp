#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool read(T &x) {
  int f = 1, c = getchar();
  x = 0;
  while (!isdigit(c)) {
    if (c == 45) f = -1;
    c = getchar();
  }
  while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
  return x *= f, true;
}
template <typename T, typename... Args>
inline bool read(T &x, Args &...args) {
  return read(x) && read(args...);
}
namespace run {
const int maxn = 1e3 + 10;
long long a[maxn];
long long ans, now, last;
int n;
inline int main() {
  read(n);
  for (register int i = 1; i <= n; ++i) read(a[i]);
  for (register int i = 1; i <= n; i += 2) {
    now = a[i], last = 0;
    for (register int j = i + 1; j <= n; ++j) {
      if (now < 0) break;
      if (j & 1) {
        now += a[j], last = a[j];
        continue;
      }
      if (a[j] < last) break;
      if (j == i + 1) {
        if (now < a[j]) {
          ans += now;
          break;
        }
        ans += a[j];
        now -= a[j];
        continue;
      }
      ans++;
      now -= a[j] - last;
      if (now >= a[j] - last)
        ans += a[j] - last;
      else {
        ans += now;
        break;
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
}
}  // namespace run
int main() { return run ::main(); }

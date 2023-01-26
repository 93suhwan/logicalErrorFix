#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, ff = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') ff = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + (c ^ '0');
    c = getchar();
  }
  return x * ff;
}
long long n, tot, x, b[100005], a[100005], cnt, ans;
signed main() {
  long long t = read();
  while (t--) {
    ans = 0;
    cnt = 0;
    n = read();
    for (long long i = 1; i <= n; i++) b[i] = 0;
    for (long long i = 1; i <= n; i++) {
      x = read();
      if (x <= n && !b[x]) {
        b[x] = 1;
        continue;
      }
      a[++cnt] = (x - 1) / 2;
    }
    sort(a + 1, a + cnt + 1);
    tot = 1;
    for (long long i = 1; i <= n; i++) {
      if (b[i]) continue;
      if (a[tot] < i) {
        ans = -1;
        break;
      }
      tot++;
      ans++;
    }
    cout << ans << endl;
  }
  return 0;
}

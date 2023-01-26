#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0;
  bool flag = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') flag = 0;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + ch - '0';
    ch = getchar();
  }
  if (flag) return x;
  return ~(x - 1);
}
int T, n;
long long s[1005], c[1005];
signed main() {
  n = read();
  for (int i = 1; i <= n; i++) {
    c[i] = read();
    if (i & 1)
      s[i] = s[i - 1] + (long long)c[i];
    else
      s[i] = s[i - 1] - (long long)c[i];
  }
  long long ans = 0ll;
  for (int i = 1; i <= n; i += 2) {
    long long ans1 = 0ll, minv = 1e18;
    for (int j = i + 1; j <= n; j++) {
      long long t = s[j - 1] - s[i];
      if (!(j & 1) && max(1ll, -minv) <= c[i] &&
          min(c[i], c[j] - t) >= max(1ll, -minv))
        ans += min(c[i], c[j] - t) - max(1ll, -minv) + 1;
      if (j & 1)
        ans1 += c[j];
      else
        ans1 -= c[j];
      minv = min(minv, ans1);
    }
  }
  cout << ans << "\n";
}

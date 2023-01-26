#include <bits/stdc++.h>
using namespace std;
inline int read() {
  register int s = 0, f = 0;
  register char ch = getchar();
  while (!isdigit(ch)) {
    f |= (ch == '-');
    ch = getchar();
  }
  while (isdigit(ch)) {
    s = (s << 1) + (s << 3) + (ch ^ 48);
    ch = getchar();
  }
  return f ? -s : s;
}
inline void write(int x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9) {
    write(x / 10);
  }
  putchar(x % 10 + '0');
}
long long a[1005], n, ans;
signed main() {
  cin >> n;
  for (auto i = 1; i <= n; i += 1) {
    cin >> a[i];
  }
  for (auto i = 1; i <= n; i += 2) {
    long long sum = 0;
    long long mn = a[i] - 1;
    for (auto j = i + 1; j <= n; j += 2) {
      sum += a[j - 1];
      sum -= a[j];
      if (sum < 0) {
        ans += min(a[j] + sum + 1, mn + 1);
        break;
      } else {
        ans += min(a[j], max(0LL, mn - sum + 1));
        if (j == i + 1) {
          mn = min(a[i], sum);
        } else {
          mn = min(mn, sum);
        }
      }
    }
  }
  cout << ans;
  return 0;
}

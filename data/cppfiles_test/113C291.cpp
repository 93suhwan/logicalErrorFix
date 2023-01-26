#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const long long mod = 1e9 + 7;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  return x * f;
}
long long a[N];
void solve() {
  int n, m;
  scanf("%d", &n);
  long long sum = 0;
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]), sum += a[i];
  sort(a + 1, a + 1 + n);
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    long long ans1 = 0, ans2 = 0;
    long long x, y;
    scanf("%lld%lld", &x, &y);
    int pos = lower_bound(a + 1, a + 1 + n, x) - a;
    pos = min(pos, n);
    if (a[pos] < x) {
      ans1 += x - a[pos];
    }
    long long p = sum - a[pos];
    if (p < y) {
      ans1 += y - p;
    }
    if (pos > 1) {
      pos--;
      if (a[pos] < x) {
        ans2 += x - a[pos];
      }
      p = sum - a[pos];
      if (p < y) {
        ans2 += y - p;
      }
    } else {
      ans2 = 2e18;
    }
    printf("%lld\n", min(ans1, ans2));
  }
}
int main() {
  int T = 1;
  while (T--) {
    solve();
  }
  return 0;
}

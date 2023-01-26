#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int T, n;
long long a[N], b[N], f[N][21], lg[N];
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
bool check(int l, int r) {
  int len = lg[r - l + 1];
  return gcd(f[l][len], f[r - (1 << len) + 1][len]) > 1;
}
namespace bl {
int solve(int n) {
  int ans = 0;
  for (int i = 1; i <= n; i++)
    for (int j = n; j >= i + ans; j--) {
      int mx = 0;
      for (int k = i; k <= j; k++) mx = max(mx, (int)a[k]);
      bool ok = false;
      for (int k = 2; k <= mx; k++) {
        bool now = true;
        for (int p = i + 1; p <= j; p++)
          if (a[p] % k != a[p - 1] % k) {
            now = false;
            break;
          }
        if (now) {
          ok = true;
          break;
        }
      }
      if (ok) {
        ans = max(ans, j - i + 1);
      }
    }
  return ans;
}
}  // namespace bl
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    for (int i = 1; i <= n - 1; i++) b[i] = abs(a[i] - a[i + 1]);
    n--;
    lg[0] = -1;
    for (int i = 1; i <= n; i++) {
      f[i][0] = b[i];
      lg[i] = lg[i >> 1] + 1;
    }
    for (int j = 1; j <= lg[n]; j++)
      for (int i = 1; i + (1 << j) - 1 <= n; i++)
        f[i][j] = gcd(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      int l = i, r = n, j = i;
      while (l <= r) {
        int mid = l + r >> 1;
        if (check(i, mid))
          j = mid, l = mid + 1;
        else
          r = mid - 1;
      }
      if (i == j && b[i] == 1) continue;
      ans = max(ans, j - i + 1);
    }
    printf("%d\n", max(1, ans + 1));
  }
  return 0;
}

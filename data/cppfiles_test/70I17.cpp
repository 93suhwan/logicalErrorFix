#include <bits/stdc++.h>
using namespace std;
int n, m;
long long a[200005], s[200005];
int h[40000005];
long long ksm(long long x, long long k) {
  if (k == 1) return x;
  long long tmp = ksm(x, k / 2);
  tmp = tmp * tmp % 1000000007;
  if (k % 2) tmp = tmp * x % 1000000007;
  return tmp;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    scanf("%lld", &a[i]), a[i] = (a[i] + 2391314) % 1000000007;
  for (int i = 1; i <= n; i++) h[a[i] % 39260671] = i;
  for (int i = 1; i <= n; i++) s[i] = (s[i - 1] + a[i]) % 1000000007;
  while (m--) {
    long long l, r, d;
    scanf("%lld%lld%lld", &l, &r, &d);
    long long tmp = (s[r] - s[l - 1] + 1000000007) % 1000000007 *
                    ksm(r - l + 1, 1000000007 - 2) % 1000000007;
    tmp =
        (tmp - (r - l) * ksm(2, 1000000007 - 2) % 1000000007 * d % 1000000007 +
         1000000007) %
        1000000007;
    int flag = 0;
    for (int i = l; i <= r; i++) {
      int t = tmp % 39260671;
      if (h[t] < l || h[t] > r) {
        flag = 1;
        break;
      }
      tmp = (tmp + d) % 1000000007;
    }
    if (flag)
      printf("No\n");
    else
      printf("Yes\n");
  }
}

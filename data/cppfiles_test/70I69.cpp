#include <bits/stdc++.h>
using namespace std;
int n, m;
long long a[200005], s[200005];
int head[40000005], cnt;
struct hash {
  int nxt, to;
} e[200005];
void add(int u, int v) {
  e[++cnt].to = v;
  e[cnt].nxt = head[u];
  head[u] = cnt;
}
int vis[200005];
bool find1(int x, int k, int l, int r) {
  if (e[x].to >= l && e[x].to <= r && vis[e[x].to] != k) {
    vis[e[x].to] = k;
    return true;
  }
  if (e[x].nxt) find1(e[x].nxt, k, l, r);
  return false;
}
bool find2(int x, int k, int l, int r) {
  if (e[x].to <= l && e[x].to >= r && vis[e[x].to] != k) {
    vis[e[x].to] = k;
    return true;
  }
  if (e[x].nxt) find2(e[x].nxt, k, l, r);
  return false;
}
long long ksm(long long x, long long k) {
  if (k == 1) return x;
  long long tmp = ksm(x, k / 2);
  tmp = tmp * tmp % 1000000007;
  if (k % 2) tmp = tmp * x % 1000000007;
  return tmp;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  for (int i = 1; i <= n; i++) add(a[i] % 39260671, i);
  for (int i = 1; i <= n; i++) s[i] = (s[i - 1] + a[i]) % 1000000007;
  while (m--) {
    long long l, r, d;
    scanf("%lld%lld%lld", &l, &r, &d);
    if (l <= r) {
      long long tmp = (s[r] - s[l - 1] + 1000000007) % 1000000007 *
                      ksm(r - l + 1, 1000000007 - 2) % 1000000007;
      tmp = (tmp -
             (r - l) * ksm(2, 1000000007 - 2) % 1000000007 * d % 1000000007 +
             1000000007) %
            1000000007;
      int flag = 0;
      for (int i = l; i <= r; i++) {
        int t = tmp % 39260671;
        if (!find1(head[t], m + 1, l, r)) {
          flag = 1;
          break;
        }
        tmp = (tmp + d) % 1000000007;
      }
      if (flag)
        printf("No\n");
      else
        printf("Yes\n");
    } else {
      long long tmp = (s[n] - s[r] + s[l - 1] + 1000000007) % 1000000007 *
                      ksm(n - (r - l + 1), 1000000007 - 2) % 1000000007;
      tmp =
          (tmp -
           (n - r + l) * ksm(2, 1000000007 - 2) % 1000000007 * d % 1000000007 +
           1000000007) %
          1000000007;
      int flag = 0;
      for (int i = l; i <= r; i++) {
        int t = tmp % 39260671;
        if (!find2(head[t], m + 1, l, r)) {
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
}

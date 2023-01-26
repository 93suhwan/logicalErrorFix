#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, cnt;
int c[N];
long long a[N], sum[N];
char st[N];
struct Edge {
  int l, r;
} p[N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  sort(a + 1, a + n + 1);
  scanf("%s", st + 1);
  for (int i = 1; i <= n; i++) c[i] = (st[i] == 'R');
  p[cnt = 1].l = 1;
  for (int i = 2; i <= n; i++)
    if (c[i] != c[i - 1]) p[cnt].r = i - 1, p[++cnt].l = i;
  p[cnt].r = n;
  int now = n - cnt;
  for (int i = 1; i <= cnt; i++) {
    int l = p[i].l, r = p[i].r;
    sum[c[l]] += a[n - cnt + i];
    printf("%lld %c\n", a[n - cnt + i], st[l]);
    for (int j = l + 1; j <= r; j++) {
      if (sum[c[l] ^ 1] + a[now] >= sum[c[l]]) {
        sum[c[l]] += a[now];
        printf("%lld %c\n", a[now], st[l]);
        now--;
      } else {
        sum[c[l] ^ 1] += a[now];
        printf("%lld %c\n", a[now], c[l] ? 'L' : 'R');
        now--;
      }
    }
  }
  return 0;
}

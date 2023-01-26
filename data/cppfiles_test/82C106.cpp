#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
int sum[maxn], t, n, q, l, r;
char s[maxn];
set<int> v[4 * maxn + 10];
int main() {
  scanf("%d", &t);
  while (t--) {
    sum[0] = 0;
    scanf("%d%d%s", &n, &q, (s + 1));
    for (int i = 1; i <= n; i++) {
      sum[i] = sum[i - 1] + (s[i] == '+' ? 1 : -1) * (i & 1 ? 1 : -1);
      v[sum[i - 1] + sum[i] + 2 * maxn].clear();
    }
    for (int i = 1; i <= n; i++) v[sum[i - 1] + sum[i] + 2 * maxn].insert(i);
    while (q--) {
      scanf("%d%d", &l, &r);
      if (sum[r] == sum[l - 1])
        printf("0\n");
      else {
        int k = r - l + 1;
        if (k % 2 == 0)
          printf("2\n%d ", l), l++;
        else
          printf("1\n");
        printf("%d\n", *v[sum[r] + sum[l - 1] + 2 * maxn].lower_bound(l));
      }
    }
  }
  return 0;
}

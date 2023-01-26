#include <bits/stdc++.h>
using namespace std;
vector<int> v[100001];
const int skc = 1e9 + 7;
int n, a[100001], i, j, k, x, u[100001], p[100001];
long long ans, sum, cnt[100001];
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    for (j = 1; j * j <= a[i]; j++)
      if (a[i] % j == 0) {
        v[i].push_back(j);
        if (j * j != a[i]) v[i].push_back(a[i] / j);
      }
  }
  for (i = 1; i <= 100000; i++) {
    x = i;
    u[i] = i;
    for (j = 2; j * j <= x; j++)
      if (x % j == 0) {
        u[i] = u[i] / j * (j - 1);
        while (x % j == 0) x /= j;
      }
    if (x != 1) u[i] = u[i] / x * (x - 1);
  }
  for (i = 1; i <= n; i++) {
    sum = 0;
    for (j = i; j <= n; j += i) p[a[j]]++;
    for (j = i; j <= n; p[a[j]] = 0, j += i)
      if (p[a[j]])
        for (k = 0; k < v[j].size(); k++)
          x = v[j][k],
          sum = (sum -
                 (cnt[x] * cnt[x] - (cnt[x] + p[a[j]]) * (cnt[x] + p[a[j]])) %
                     skc * u[x]) %
                skc,
          cnt[x] += p[a[j]];
    for (j = i; j <= n; j += i) p[a[j]]++;
    for (j = i; j <= n; p[a[j]] = 0, j += i)
      for (k = 0; k < v[j].size(); k++) x = v[j][k], cnt[x] -= p[a[j]];
    ans = (ans + sum * u[i]) % skc;
  }
  printf("%lld\n", (ans + skc) % skc);
}

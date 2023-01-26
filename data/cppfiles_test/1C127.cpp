#include <bits/stdc++.h>
using namespace std;
const int N = 6005;
int n, x[N], y[N], d[N];
long long ans;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d%d", &x[i], &y[i]), x[i] /= 2, y[i] /= 2;
  for (int i = 2; i <= n; i++)
    for (int j = 1; j < i; j++)
      if ((x[i] - x[j]) % 2 == 0 && (y[i] - y[j]) % 2 == 0) d[i]++, d[j]++;
  for (int i = 2; i <= n; i++)
    for (int j = 1; j < i; j++)
      if ((x[i] - x[j]) % 2 == 0 && (y[i] - y[j]) % 2 == 0)
        ans += 3 * (n - 1 - d[i]), ans += d[i] - 1;
  printf("%lld\n", ans / 3);
}

#include <bits/stdc++.h>
using namespace std;
int n;
int keep_a[200007];
int keep_b[200007];
long long sub[200007];
long long pre_sub[200007];
long long dif[200007];
long long pre_dif[200007];
int main() {
  int t = 0;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    long long ans = (long long)n * (n - 1) * (n - 2) / 6;
    for (int i = 1; i <= n; i++) {
      sub[i] = 0;
      dif[i] = 0;
      pre_dif[i] = 0;
      pre_sub[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
      long long a = 0, b = 0;
      scanf("%lld%lld", &a, &b);
      keep_a[i] = a;
      keep_b[i] = b;
      sub[a]++;
      dif[b]++;
    }
    long long ans2 = 0;
    long long sum_sub = 0;
    long long sum_dif = 0;
    for (int i = 1; i <= n; i++) {
      if (sub[i] > 1) {
        pre_sub[i] = sub[i] * (sub[i] - 1) / 2;
        sum_sub += pre_sub[i];
      }
      if (dif[i] > 1) {
        pre_dif[i] = dif[i] * (dif[i] - 1) / 2;
        sum_dif += pre_dif[i];
      }
    }
    for (int i = 1; i <= n; i++) {
      ans2 += pre_sub[i] * sum_dif;
      ans2 += pre_dif[i] * sum_sub;
      ans2 -= (sub[keep_a[i]] - 1) * (dif[keep_b[i]] - 1);
    }
    printf("%lld\n", ans - ans2);
  }
  return 0;
}

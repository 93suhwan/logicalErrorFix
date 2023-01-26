#include <bits/stdc++.h>
using namespace std;
const int N = 10007;
long long a[N], sum[N];
long long ask(int x, int y) {
  long long u, v;
  printf("and %d %d\n", x, y);
  fflush(stdout);
  scanf("%lld", &u);
  printf("or %d %d\n", x, y);
  fflush(stdout);
  scanf("%lld", &v);
  long long ans = u + v;
  return ans;
}
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  sum[1] = ask(1, 2);
  sum[2] = ask(2, 3);
  sum[3] = ask(3, 1);
  a[1] = (sum[1] - sum[2] + sum[3]) / 2;
  a[2] = (sum[2] - sum[3] + sum[1]) / 2;
  a[3] = (sum[3] - sum[1] + sum[2]) / 2;
  for (int i = 4; i <= n; i++) {
    sum[i] = ask(1, i);
    a[i] = sum[i] - a[1];
  }
  sort(a + 1, a + 1 + n);
  printf("finish %lld\n", a[k]);
  return 0;
}

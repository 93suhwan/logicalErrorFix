#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int n, m, a[N], b[N], x[N], y[N];
long long ans, sum1, sum2;
void Work() {
  bool flag = 0;
  sum1 = sum2 = 0;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &a[i], &b[i]);
    sum1 += a[i];
    sum2 += b[i];
  }
  if (sum1 > sum2) {
    for (int i = 1; i <= n; i++) swap(a[i], b[i]);
    flag = 1;
  }
  ans = 0;
  for (int i = 1; i <= n; i++) {
    x[i] = min(m, a[i]);
    y[i] = max(m - a[i], 0);
    ans = ans - (a[i] - x[i]) + (b[i] - y[i]);
  }
  for (int i = 1; i <= n; i++) {
    int cnt = min(min(ans / 2LL, 1LL * b[i] - y[i]), 1LL * x[i]);
    ans -= 2LL * cnt;
    x[i] -= cnt;
    y[i] += cnt;
  }
  if (flag) {
    for (int i = 1; i <= n; i++) swap(x[i], y[i]);
  }
  cout << abs(ans) << "\n";
  for (int i = 1; i <= n; i++) cout << x[i] << " " << y[i] << "\n";
}
int main() {
  int T = 1;
  scanf("%d", &T);
  while (T--) Work();
  return 0;
}

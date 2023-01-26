#include <bits/stdc++.h>
void solve() {
  int n;
  scanf("%d", &n);
  long long sum = 0;
  int max = INT_MIN;
  for (int i = 0; i < n; i++) {
    int num;
    scanf("%d", &num);
    sum += num;
    if (max < num) {
      max = num;
    }
  }
  printf("%lf\n", (double)(sum - max) / (n - 1) + max);
}
int main() {
  int ntc;
  scanf("%d", &ntc);
  for (int tc = 1; tc <= ntc; tc++) {
    solve();
  }
  return 0;
}

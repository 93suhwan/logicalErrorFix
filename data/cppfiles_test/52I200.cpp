#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int a[N];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, sum = 0, maxn = -1e9;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      sum += a[i];
      maxn = max(a[i], maxn);
    }
    printf("%0.9lf", maxn * 1.0 + (sum - maxn) * 1.0 / (n - 1));
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n, a[200005];
int abs(int a) {
  if (a > 0)
    return a;
  else
    return -a;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
    }
    sort(a + 1, a + 1 + n);
    long long int res = (long long int)a[1];
    for (int i = 1; i <= n - 1; i++) {
      long long int k = (long long int)a[i + 1] - a[i];
      res = max(res, k);
    }
    printf("%lli\n", res);
  }
}

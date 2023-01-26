#include <bits/stdc++.h>
using namespace std;
long long a[200], b[200];
int main() {
  int t;
  scanf("%d", &t);
  for (int i = 1; i <= t; i++) {
    int n;
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    scanf("%d", &n);
    for (int j = 1; j <= n; j++) {
      scanf("%lld", &a[j]);
      b[j] = a[j] - j;
    }
    sort(b + 1, b + n + 1);
    printf("%lld\n", b[n]);
  }
  return 0;
}

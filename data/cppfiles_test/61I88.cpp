#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[200010], b[200010];
int v1[200010], v2[200010];
int main() {
  cin >> t;
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) v1[i] = v2[i] = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d%d", &a[i], &b[i]);
      v1[a[i]]++;
      v2[b[i]]++;
    }
    long long s = n * (n - 1) * (n - 2) / 6;
    for (int i = 1; i <= n; i++) {
      s -= (v1[a[i]] - 1) * (v2[b[i]] - 1);
    }
    printf("%lld\n", s);
  }
}

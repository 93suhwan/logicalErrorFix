#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a[200000];
  int t, n, k;
  long long sum = 0, ans = 0;
  memset(a, 0, sizeof(a));
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> t;
    for (int i = 1; i <= t; i++) cin >> a[i];
    sort(a + 1, a + t + 1);
    for (int i = 1; i <= t - 1; i++) ans += a[i];
    printf("%.9lf\n", double(ans) / (t - 1) * 1.0 + a[t]);
  }
}

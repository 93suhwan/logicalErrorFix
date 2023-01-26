#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const long long inf = 1e18;
long long a[maxn];
int t, n, k;
int main() {
  cin >> t;
  while (t--) {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    long long result = -inf;
    for (int i = max(1, n - 500); i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        long long u = i * j;
        long long w = (a[i] | a[j]);
        result = max(result, u - k * w);
      }
    }
    printf("%lld\n", result);
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n, k;
    scanf("%lld %lld", &n, &k);
    long long int a[n];
    for (int i = 0; i < n; ++i) {
      scanf("%lld", a + i);
    }
    long long int max1 = INT_MIN;
    for (long long int i = n - 1; i > -1; --i) {
      for (long long int j = i - 1; j > -1; --j) {
        if ((i + 1) * (j + 1) < max1) break;
        max1 = max(max1, (i + 1) * (j + 1) - k * (a[i] | a[j]));
      }
    }
    printf("%lld\n", max1);
  }
}

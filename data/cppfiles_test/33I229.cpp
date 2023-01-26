#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);
    sort(a.begin(), a.end());
    printf("%I64d\n", a[n - 2] * a[n - 1]);
  }
}

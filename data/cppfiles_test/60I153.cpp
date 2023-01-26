#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a, b, c, t, n, m, mm, h;
  scanf("%lld", &t);
  while (t--) {
    scanf("%lld", &n);
    vector<long long int> arr(n);
    map<long long int, long long int> mp;
    m = 0;
    for (long long int i = 0; i < n; i++) {
      scanf("%lld", &arr[i]);
      m += arr[i];
      mp[arr[i]]++;
    }
    mm = m / n;
    if (mm * n != m) {
      printf("%lld\n", 0LL);
      continue;
    }
    a = mm * 2;
    c = 0;
    for (long long int i = 0; i < n; i++) {
      b = a - arr[i];
      c += mp[b];
      if (b == arr[i]) c--;
    }
    c /= 2;
    printf("%lld\n", c);
  }
  return 0;
}

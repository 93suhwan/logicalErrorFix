#include <bits/stdc++.h>
using namespace std;
long long a[200005];
map<long long, int> mp;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long n;
    scanf("%lld", &n);
    long long sum = 0;
    mp.clear();
    for (int i = 1; i <= n; i++) {
      scanf("%lld", &a[i]);
      sum += a[i];
    }
    long long res = 0;
    for (int i = 1; i <= n; i++) {
      res += mp[2 * sum - n * a[i]];
      mp[n * a[i]]++;
    }
    printf("%lld\n", res);
  }
}

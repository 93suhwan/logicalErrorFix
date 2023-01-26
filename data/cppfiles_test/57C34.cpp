#include <bits/stdc++.h>
using namespace std;
long long T, n, k, s;
signed main() {
  scanf("%lld", &T);
  while (T--) {
    scanf("%lld%lld%lld", &s, &n, &k);
    if (s == k || s - n < (n / k) * k)
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}

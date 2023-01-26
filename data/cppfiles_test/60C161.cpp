#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
const int inf = 1000000000;
long long mod = 1000000007LL;
long long mod2 = 998244353LL;
int t, n, m, k;
int a[200005];
int main() {
  cin >> t;
  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d", &n);
    int res = 0;
    for (int i = 1; i <= n; ++i) {
      int x;
      scanf("%d", &x);
      if (i == 1)
        res = x;
      else
        res &= x;
    }
    printf("%d\n", res);
  }
  return 0;
}

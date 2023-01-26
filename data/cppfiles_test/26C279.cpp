#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:1024000000")
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double eqs = 1e-9;
const int MAXN = 100000 + 10;
int a[300];
int main() {
  int t, n;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    long long ret = 1;
    for (int i = 3; i <= (2 * n); i++) {
      ret = ret * i % mod;
    }
    printf("%lld\n", ret);
  }
  return 0;
}

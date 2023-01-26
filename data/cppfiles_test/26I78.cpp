#include <bits/stdc++.h>
using namespace std;
const int nmax = 2e5 + 10;
const long long mod = 1e9 + 7;
long long val[nmax];
int main() {
  int T;
  scanf("%d", &T);
  val[2] = 1;
  for (int i = 3; i < nmax; i++) {
    val[i] = val[i - 1] * i % mod;
  }
  while (T--) {
    int x;
    scanf("%d", &x);
    printf("%lld", val[2 * x]);
  }
  return 0;
}

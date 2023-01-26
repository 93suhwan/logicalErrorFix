#include <bits/stdc++.h>
using namespace std;
int T;
long long n, m, k;
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%lld%lld%lld", &n, &m, &k);
    int sf;
    if (n == 1 && m == 0 && k > 1)
      sf = 1;
    else if (m < n - 1 || m > n * (n - 1) / 2)
      sf = 0;
    else if (m == n * (n - 1) / 2 && k > 2)
      sf = 1;
    else if (m >= n - 1 && m < n * (n - 1) / 2 && k > 3)
      sf = 1;
    else
      sf = 0;
    if (sf)
      printf("YES\n");
    else
      printf("NO\n");
  }
}

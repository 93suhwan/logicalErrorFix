#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int T, n, a[N];
int main() {
  scanf("%d", &T);
  for (int tc = (1); tc <= (T); tc++) {
    scanf("%d", &n);
    for (int i = (1); i <= (n); i++) scanf("%d", &a[i]);
    long long ret = 0;
    for (int i = (1); i <= (n - 1); i++) ret = max(ret, 1ll * a[i] * a[i + 1]);
    printf("%lld\n", ret);
  }
  return 0;
}

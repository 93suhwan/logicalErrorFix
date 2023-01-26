#include <bits/stdc++.h>
using namespace std;
int T;
long long s, n, k;
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%lld%lld%lld", &s, &n, &k);
    long long cnt = (s / (2 * k)) * k + min(s % (2 * k), k - 1);
    if (n > cnt)
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}

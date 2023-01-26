#include <bits/stdc++.h>
using namespace std;
int T, s, n, k;
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d%d", &s, &n, &k);
    int w = n / k * 2ll * k + n % k;
    if (s < w)
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}

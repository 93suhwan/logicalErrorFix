#include <bits/stdc++.h>
using namespace std;
const int lim = 3e5 + 5;
int f[lim];
int main() {
  int T, a, b, ans;
  scanf("%d", &T);
  for (int i = 1; i < lim; ++i) f[i] = f[i - 1] ^ i;
  while (T--) {
    scanf("%d %d", &a, &b);
    if (f[a - 1] == b)
      ans = a;
    else {
      if (f[a] == b)
        ans = a + 2;
      else
        ans = a + 1;
    }
    printf("%d\n", ans);
  }
  return 0;
}

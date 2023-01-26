#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    if (n % 2 == 1) {
      k = n * m / 2 - k;
      n ^= m;
      m ^= n;
      n ^= m;
    }
    if (k % 2 == 0 && k <= m / 2 * n)
      puts("YES");
    else
      puts("NO");
  }
}

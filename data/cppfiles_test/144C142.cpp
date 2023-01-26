#include <bits/stdc++.h>
using namespace std;
int T, n, m, k, pos;
void color(int mod, int d) {
  for (int i = 1; i <= mod; ++i) {
    printf("%d", d + 1);
    for (int j = 0; j <= d; ++j) {
      printf(" %d", (pos++) % n + 1);
    }
    puts("");
  }
  for (int i = mod + 1; i <= m; ++i) {
    printf("%d", d);
    for (int j = 0; j < d; ++j) {
      printf(" %d", (pos++) % n + 1);
    }
    puts("");
  }
}
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d%d", &n, &m, &k);
    int d = n / m, mod = n % m;
    pos = 0;
    for (int i = 1; i <= k; ++i) color(mod, d), pos -= (m - mod) * d;
    puts("");
  }
  return 0;
}

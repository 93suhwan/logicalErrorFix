#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAX_N = 2e5 + 10;
int n, m, k;
void solve() {
  scanf("%d%d%d", &n, &m, &k);
  int row = k, col = n * m / 2 - k;
  if (m % 2 == 1 && col == 0) {
    printf("NO\n");
  } else if (n % 2 == 1 && row == 0) {
    printf("NO\n");
  } else if (col % 2 != m % 2) {
    printf("NO\n");
  } else if (row % 2 != n % 2) {
    printf("NO\n");
  } else if (row == 0 && n % 2 != 0) {
    printf("NO\n");
  } else if (col == 0 && m % 2 != 0) {
    printf("NO\n");
  } else {
    printf("YES\n");
  }
}
int main() {
  int TCASE = 1;
  scanf("%d", &TCASE);
  getchar();
  while (TCASE--) solve();
  return 0;
}

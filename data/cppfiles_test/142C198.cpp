#include <bits/stdc++.h>
using namespace std;
int t, n, m, p[100005], M[100005], M2[100005];
int main() {
  scanf("%d", &t);
  for (int q = 1; q <= t; q++) {
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= n; i++) M2[i] = M[i] = 0;
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        scanf("%d", &p[j]);
        M[j] = max(M[j], p[j]);
      }
      sort(p + 1, p + n + 1);
      M2[i] = p[n - 1];
    }
    sort(M + 1, M + n + 1);
    if (m >= n - 1) {
      sort(M2 + 1, M2 + m + 1);
      printf("%d\n", min(M2[m], M[1]));
      continue;
    }
    printf("%d\n", M[1]);
  }
  return 0;
}

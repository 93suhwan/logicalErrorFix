#include <bits/stdc++.h>
using namespace std;
int n, i, j, a[100001], b[515], c[515], k;
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; i = i + 1) scanf("%d", &a[i]);
  for (i = 1; i <= 511; i = i + 1) b[i] = 99999999;
  for (i = 1; i <= n; i = i + 1) {
    b[a[i]] = min(b[a[i]], a[i]);
    for (j = 0; j <= 511; j = j + 1) {
      if (b[j] < a[i] && b[j] != 99999999) b[j ^ a[i]] = min(b[j ^ a[i]], a[i]);
    }
  }
  for (i = 0; i <= 511; i = i + 1)
    if (b[i] != 99999999) c[++k] = i;
  printf("%d\n", k);
  for (i = 1; i <= k; i = i + 1) printf("%d ", c[i]);
  return 0;
}

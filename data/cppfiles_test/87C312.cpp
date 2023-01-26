#include <bits/stdc++.h>
using namespace std;
const int MaxN = 5e2 + 5;
const int MaxM = 5e2 + 5;
int t, n, m, a[MaxN], c[MaxN];
long long ans;
void mergesort(int l, int r) {
  if (l == r) {
    return;
  }
  int mid = (l + r) >> 1;
  register int i = l, j = mid + 1, k = l;
  mergesort(l, mid);
  mergesort(mid + 1, r);
  while (i <= mid && j <= r) {
    if (a[i] <= a[j]) {
      c[k++] = a[i++];
    } else {
      c[k++] = a[j++];
      ans += mid - i + 1;
    }
  }
  while (i <= mid) {
    c[k++] = a[i++];
  }
  while (j <= r) {
    c[k++] = a[j++];
  }
  for (register int h = l; h <= r; h++) {
    a[h] = c[h];
  }
}
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &m);
    for (register int i = 1; i <= n; i++) {
      for (register int j = 1; j <= m; j++) {
        scanf("%d", &a[j]);
        a[j] = -a[j];
      }
    }
    ans = 0;
    mergesort(1, m);
    printf("%lld\n", ans);
  }
  return 0;
}

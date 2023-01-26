#include <bits/stdc++.h>
using namespace std;
int t, n, a[500010], b[500010], cnt[500010], ans;
void mergesort(int l, int r) {
  if (l >= r) return;
  int mid = (l + r) / 2;
  mergesort(l, mid), mergesort(mid + 1, r);
  int i = l, j = mid + 1, n = mid, m = r, k = 0;
  while (i <= n && j <= m)
    if (a[i] > a[j])
      ans += n - i + 1, b[k++] = a[j++];
    else
      b[k++] = a[i++];
  while (i <= n) b[k++] = a[i++];
  while (j <= m) b[k++] = a[j++];
  for (i = 0; i < k; i++) a[l + i] = b[i];
}
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) cnt[i] = 0;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]), cnt[a[i]]++;
    bool flag = false;
    for (int i = 1; i <= n; i++) flag |= cnt[i] > 1;
    ans = 0, mergesort(1, n);
    if (flag)
      printf("YES\n");
    else if (ans % 2 == 0)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}

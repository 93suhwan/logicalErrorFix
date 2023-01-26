#include <bits/stdc++.h>
int a[200005], l, r, n;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  l = 1, r = n;
  while (l < n && a[l] < a[l + 1]) l++;
  while (r > l && a[r] < a[r - 1]) r--;
  printf("%s\n", ((l & 1) || ((n - r + 1) & 1)) ? "Alice" : "Bob");
  return 0;
}

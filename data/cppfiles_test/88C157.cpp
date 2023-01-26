#include <bits/stdc++.h>
int tcase, n, A[100010];
int main() {
  scanf("%d", &tcase);
  while (tcase--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    bool flag = false;
    for (int i = 2; i <= n; i++)
      if (A[i] <= A[i - 1]) flag = true;
    if (n % 2 == 0 || flag)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}

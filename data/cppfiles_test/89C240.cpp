#include <bits/stdc++.h>
using namespace std;
int t, n, a[100005] = {0};
bool flag;
int main() {
  scanf("%d", &t);
  for (int q = 1; q <= t; q++) {
    flag = 1;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n && flag; i++)
      for (int j = 2; j <= i + 1; j++)
        if (a[i] % j)
          break;
        else if (j == i + 1)
          flag = 0;
    if (flag)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}

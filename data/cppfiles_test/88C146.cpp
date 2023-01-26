#include <bits/stdc++.h>
using namespace std;
const int maxn = 300005;
int i, n, t;
int a[maxn];
bool flag1, flag2;
int main() {
  scanf("%d", &t);
  while (t--) {
    flag1 = true, flag2 = false;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%d", &a[i]);
    if (n % 2 == 1) flag1 = false;
    for (i = 2; i <= n; i++)
      if (a[i] <= a[i - 1]) flag2 = true;
    if (flag1 || flag2)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
int t;
int n;
int a[MAXN];
int main() {
  scanf("%d", &t);
  while (t--) {
    int q = 1;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
      int r = i + 1, l = 2;
      int flag = 0;
      while (l <= r) {
        if (a[i] % r) {
          flag = 1;
          break;
        }
        r--;
      }
      if (!flag) {
        printf("NO\n");
        q = 0;
        break;
      }
    }
    if (q) {
      printf("YES\n");
    }
  }
}

#include <bits/stdc++.h>
using namespace std;
int a[101000];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, x, mark;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &x);
      mark = 0;
      for (int j = i + 1; j >= 2; j--) {
        if (x % j) {
          mark = 1;
          break;
        }
      }
      if (!mark) break;
    }
    if (!mark)
      printf("NO\n");
    else
      printf("YES\n");
  }
}

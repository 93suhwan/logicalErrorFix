#include <bits/stdc++.h>
using namespace std;
char pp[300010];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    char p[10];
    int n;
    scanf("%d%s", &n, p);
    scanf("%s", pp + 1);
    int ok = 1;
    for (int i = 1; i <= n; i++) {
      if (pp[i] != p[0]) ok = 0;
    }
    if (ok)
      printf("0\n");
    else {
      int flag = 1;
      for (int i = 1; i <= n; i++) {
        if (pp[i] == p[0]) {
          ok = 1;
          for (int j = 1; j * i <= n; j++) {
            if (pp[j * i] != p[0]) ok = 0;
          }
          if (ok) {
            printf("1\n");
            printf("%d\n", i);
            flag = 0;
            break;
          }
        }
      }
      if (flag) {
        printf("2\n");
        printf("%d ", n - 1);
        printf("%d\n", n);
      }
    }
  }
}

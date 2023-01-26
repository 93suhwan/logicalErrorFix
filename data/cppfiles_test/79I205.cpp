#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    char num[55];
    int k;
    scanf("%d", &k);
    scanf("%s", num + 1);
    int sum = 0;
    for (int i = 1; i <= k; i++) sum += num[i] - '0';
    if ((sum % 3 == 0 && !(k == 1 && num[1] == '3')) ||
        ((num[k] - '0') % 2 == 0 && !(k == 1 && num[1] == '2')))
      printf("%s", num + 1);
    else {
      int ned = sum % 3, c1 = 0, c2 = 0;
      bool flag = false;
      for (int i = 1; i <= k; i++) {
        if ((num[i] - '0') % 3 == 1)
          c1++;
        else if ((num[i] - '0') % 3 == 2)
          c2++;
      }
      if (c1 >= 2 || (ned == 2 && c2 > 0)) {
        if (c1 >= 2) {
          for (int i = 1; i <= k; i++) {
            if ((num[i] - '0') % 3 == 1 && ned) {
              ned--;
              continue;
            }
            printf("%c", num[i]);
          }
        } else {
          for (int i = 1; i <= k; i++) {
            if ((num[i] - '0') % 3 == 2 && ned) {
              ned -= 2;
              continue;
            }
            printf("%c", num[i]);
          }
        }
      } else {
        int now = k;
        while ((num[now] - '0') % 2) now--;
        if (now)
          for (int i = 1; i <= now; i++) printf("%c", num[i]);
      }
    }
    printf("\n");
  }
  return 0;
}

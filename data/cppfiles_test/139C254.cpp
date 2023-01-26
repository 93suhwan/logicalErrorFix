#include <bits/stdc++.h>
int main() {
  int t;
  scanf("%d", &t);
  char st[100];
  while (t--) {
    scanf("%s", st);
    int l = strlen(st);
    int count = 0;
    if (l % 2 != 0) {
      printf("NO\n");
    } else {
      for (int i = 0; i < l; i++) {
        if (st[i] == st[(l / 2) + i]) {
          count++;
        }
      }
      if (count == l / 2) {
        printf("YES\n");
      } else {
        printf("NO\n");
      }
    }
  }
}

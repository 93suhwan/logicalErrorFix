#include <bits/stdc++.h>
using namespace std;
char s[10005];
int vis[20];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++) {
      int x = s[i] - '0';
      if (x != 2 && x != 3 && x != 5 && x != 7) {
        printf("1\n");
        printf("%d\n", x);
        break;
      }
      if (vis[x]) {
        printf("2\n");
        printf("%d%d\n", x, x);
        break;
      }
      if (x == 2 || x == 5) {
        int f = 0;
        for (int j = 0; j <= 9; j++) {
          if (vis[j]) {
            printf("2\n");
            printf("%d%d\n", j, x);
            f = 1;
            break;
          }
        }
        if (f) break;
      }
      if (x == 7) {
        if (vis[2]) {
          printf("2\n");
          printf("27\n");
          break;
        }
      }
      vis[x] = 1;
    }
  }
  return 0;
}

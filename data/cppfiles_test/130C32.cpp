#include <bits/stdc++.h>
using namespace std;
int a[100001], c[100001];
bool b[100001];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int x = -1, y = -1;
    for (int i = 0; i < n / 3; i++) {
      printf("? %d %d %d\n", 3 * i + 1, 3 * i + 2, 3 * i + 3);
      fflush(stdout);
      int z;
      scanf("%d", &z);
      if (!z) {
        if (x == -1) x = i;
      } else if (y == -1)
        y = i;
      c[i] = z;
    }
    printf("? %d %d %d\n", 3 * x + 1, 3 * x + 2, 3 * y + 1);
    fflush(stdout);
    int z1;
    scanf("%d", &z1);
    printf("? %d %d %d\n", 3 * x + 1, 3 * x + 2, 3 * y + 2);
    fflush(stdout);
    int z2;
    scanf("%d", &z2);
    int xx = 0;
    if (!z1 && !z2)
      xx = 3 * x + 1;
    else
      xx = 3 * x + 3;
    printf("? %d %d %d\n", 3 * y + 1, 3 * y + 2, 3 * x + 1);
    fflush(stdout);
    scanf("%d", &z1);
    printf("? %d %d %d\n", 3 * y + 1, 3 * y + 2, 3 * x + 2);
    fflush(stdout);
    scanf("%d", &z2);
    int yy = 0;
    if (z1 && z2)
      yy = 3 * y + 1;
    else
      yy = 3 * y + 3;
    int cnt = 1;
    a[1] = xx;
    for (int i = 0; i < n / 3; i++)
      if (i != x && i != y) {
        if (!c[i]) {
          printf("? %d %d %d\n", yy, 3 * i + 1, 3 * i + 2);
          fflush(stdout);
          scanf("%d", &z1);
          printf("? %d %d %d\n", yy, 3 * i + 2, 3 * i + 3);
          fflush(stdout);
          scanf("%d", &z2);
          if (!z1)
            if (!z2)
              a[++cnt] = 3 * i + 1, a[++cnt] = 3 * i + 2, a[++cnt] = 3 * i + 3;
            else
              a[++cnt] = 3 * i + 1, a[++cnt] = 3 * i + 2;
          else if (!z2)
            a[++cnt] = 3 * i + 2, a[++cnt] = 3 * i + 3;
          else
            a[++cnt] = 3 * i + 1, a[++cnt] = 3 * i + 3;
        } else {
          printf("? %d %d %d\n", xx, 3 * i + 1, 3 * i + 2);
          fflush(stdout);
          scanf("%d", &z1);
          printf("? %d %d %d\n", xx, 3 * i + 2, 3 * i + 3);
          fflush(stdout);
          scanf("%d", &z2);
          if (!z1)
            if (!z2)
              a[++cnt] = 3 * i + 2;
            else
              a[++cnt] = 3 * i + 1;
          else if (!z2)
            a[++cnt] = 3 * i + 3;
        }
      } else {
        for (int j = 3 * i + 1; j <= 3 * i + 3; j++)
          if (j != xx && j != yy) {
            printf("? %d %d %d\n", xx, yy, j);
            fflush(stdout);
            scanf("%d", &z1);
            if (!z1) a[++cnt] = j;
          }
      }
    cout << "!"
         << " " << cnt;
    for (int i = 1; i <= cnt; i++) {
      cout << " " << a[i];
    }
    cout << endl;
    fflush(stdout);
  }
}

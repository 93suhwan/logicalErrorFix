#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int a[1005][1005];
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
  for (int i = 1; i <= k; i++) {
    int x;
    scanf("%d", &x);
    int nowx = 1, nowy = x;
    while (nowx <= n) {
      if (a[nowx][nowy] == 1) {
        a[nowx][nowy] = 2;
        nowy++;
      } else if (a[nowx][nowy] == 2)
        nowx++;
      else {
        a[nowx][nowy] = 2;
        nowy--;
      }
    }
    printf("%d ", nowy);
  }
  return 0;
}

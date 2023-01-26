#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 5e5 + 10;
char mp[510][510];
int ans[510][510];
void run() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%s", mp[i] + 1);
  }
  int p = 0;
  for (int i = 0; i <= n + 1; i++) {
    mp[i][0] = 'X';
    mp[i][m + 1] = 'X';
  }
  for (int i = 0; i <= m + 1; i++) {
    mp[0][i] = 'X';
    mp[n + 1][i] = 'X';
  }
  for (int i = 1; i <= n; i++) {
    p = 0;
    for (int j = 1; j <= m; j++) {
      if (mp[i][j] == 'X') {
        p ^= (mp[i - 1][j] == 'X');
        int num = 0;
        if (mp[i][j - 1] == '.') num++;
        if (mp[i][j + 1] == '.') num++;
        if (mp[i - 1][j] == '.') num++;
        if (mp[i + 1][j] == '.') num++;
        if (num & 1) {
          printf("NO\n");
          return;
        }
        if (num == 0) {
          ans[i][j] = 0;
        }
        if (num == 2) {
          ans[i][j] = 5;
        }
        if (num == 4) {
          ans[i][j] = 10;
        }
      } else {
        ans[i][j] = ((j + p) & 1) ? 1 : 4;
      }
    }
  }
  printf("YES\n");
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      printf("%d ", ans[i][j]);
    }
    puts("");
  }
}
int main() {
  run();
  return 0;
}

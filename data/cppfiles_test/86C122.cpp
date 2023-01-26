#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int T, n, cnt;
char s[3][maxn];
bool flag[maxn];
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    scanf("%s", s[1] + 1);
    scanf("%s", s[2] + 1);
    cnt = 0;
    for (int i = 1; i <= n; i++) flag[i] = 0;
    for (int i = 1; i <= n; i++)
      if (s[1][i] - '0' + s[2][i] - '0' == 1) flag[i] = 1, cnt += 2;
    for (int i = 1; i <= n; i++) {
      if (s[1][i] - '0' + s[2][i] - '0' == 2) {
        bool check = 0;
        for (int j = i - 1; j >= 1; j--) {
          if (s[1][j] - '0' + s[2][j] - '0' >= 1)
            break;
          else if (flag[j] == 0) {
            flag[j] = 1;
            cnt += 2;
            check = 1;
            break;
          }
        }
        if (!check) {
          for (int j = i + 1; j <= n; j++) {
            if (s[1][j] - '0' + s[2][j] - '0' >= 1)
              break;
            else if (flag[j] == 0) {
              flag[j] = 1;
              cnt += 2;
              break;
            }
          }
        }
      }
    }
    for (int i = 1; i <= n; i++)
      if (s[1][i] - '0' + s[2][i] - '0' == 0 && flag[i] == 0) cnt++;
    printf("%d\n", cnt);
  }
}

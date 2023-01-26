#include <bits/stdc++.h>
using namespace std;
inline void read(int &res) {
  char c;
  int f = 1;
  res = 0;
  c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9')
    res = (res << 1) + (res << 3) + c - 48, c = getchar();
  res *= f;
}
int T, n, m;
int ans, cnt;
int mp[405][405];
int hqz[405][405];
int sqz[405][405];
char c[405];
int main() {
  read(T);
  while (T--) {
    read(n);
    read(m);
    ans = 1e9;
    for (int i = 1; i <= n; i++) {
      scanf("%s", c + 1);
      for (int j = 1; j <= m; j++) {
        mp[i][j] = c[j] - '0';
        hqz[i][j] = hqz[i][j - 1] + mp[i][j];
        sqz[i][j] = sqz[i - 1][j] + mp[i][j];
      }
    }
    for (int i = 1; i + 4 <= n; i++) {
      for (int j = 1; j + 3 <= m; j++) {
        for (int k = i + 4; k <= n; k++) {
          cnt = sqz[k - 1][j] - sqz[i][j];
          cnt = (k - i - 1) - cnt;
          cnt += 1 - hqz[i][j + 1] + hqz[i][j];
          cnt += sqz[k - 1][j + 1] - sqz[i][j + 1];
          if (cnt >= ans) break;
          cnt += 1 - hqz[k][j + 1] + hqz[k][j];
          for (int l = j + 3; l <= m; l++) {
            cnt += mp[i][l - 1] ^ 1;
            cnt += mp[k][l - 1] ^ 1;
            cnt += sqz[k - 1][l - 1] - sqz[i][l - 1];
            if (cnt >= ans) break;
            if (cnt + (k - i - 1) - sqz[k - 1][l] + sqz[i][l] < ans)
              ans = cnt + (k - i - 1) - sqz[k - 1][l] + sqz[i][l];
          }
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}

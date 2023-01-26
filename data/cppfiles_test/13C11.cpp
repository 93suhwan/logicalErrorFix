#include <bits/stdc++.h>
using namespace std;
bool judge(int n, int m, int k) {
  if (n & 1) {
    swap(n, m);
    k = n * m / 2 - k;
  }
  if (m == 1)
    return (k == n % 2);
  else {
    if (m & 1) {
      int inf = n * (m - 1) / 2;
      return !((k & 1) | (k > inf));
    } else
      return !(k & 1);
  }
}
int ans[110][110];
int dd_heng[2][2] = {-1, 0, 0, -1};
int dd_shu[3][2] = {-1, 0, 0, -1, 1, -1};
int cnt[10];
int judge_heng(int x, int y) {
  for (int i = 1; i <= 4; i++) cnt[i] = 0;
  for (int i = 0; i < 2; i++) cnt[ans[x + dd_heng[i][0]][y + dd_heng[i][1]]]++;
  for (int i = 1; i <= 4; i++)
    if (!cnt[i]) return i;
  return 5;
}
int judge_shu(int x, int y) {
  for (int i = 1; i <= 4; i++) cnt[i] = 0;
  for (int i = 0; i < 3; i++) cnt[ans[x + dd_shu[i][0]][y + dd_shu[i][1]]]++;
  for (int i = 1; i <= 4; i++)
    if (!cnt[i]) return i;
  return 5;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m, k;
    cin >> n >> m >> k;
    if (!judge(n, m, k)) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    memset(ans, 0, sizeof ans);
    int swapflag = 0;
    if (n & 1) {
      swap(n, m);
      k = n * m / 2 - k;
      swapflag = 1;
    }
    for (int j = 1; j <= m; j++)
      for (int i = 1; i <= n; i++)
        if (!ans[i][j]) {
          int color = 0;
          if (k) {
            color = judge_heng(i, j), k--;
            ans[i][j] = ans[i][j + 1] = color;
          } else {
            color = judge_shu(i, j);
            ans[i][j] = ans[i + 1][j] = color;
          }
        }
    if (!swapflag) {
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) cout << char(ans[i][j] + 'a' - 1);
        cout << "\n";
      }
    } else {
      for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) cout << char(ans[i][j] + 'a' - 1);
        cout << "\n";
      }
    }
  }
}

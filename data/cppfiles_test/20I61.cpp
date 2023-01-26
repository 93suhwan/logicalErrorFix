#include <bits/stdc++.h>
using namespace std;
const int maxn = 410;
char a[maxn][maxn];
int arr[maxn][maxn];
int s[maxn][maxn];
int t;
int query(int x1, int y1, int x2, int y2) {
  return s[x2][y2] - s[x2][y1 - 1] - s[x1 - 1][y2] + s[x1 - 1][y1 - 1];
}
int main() {
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      scanf("%s", a[i] + 1);
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        arr[i][j] = a[i][j] - '0';
      }
    }
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        s[i][j] = s[i - 1][j] + s[i][j - 1] + arr[i][j] - s[i - 1][j - 1];
    int res = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        for (int x = i + 4; x <= n; x++)
          for (int y = j + 3; y <= m; y++) {
            int temp = 0;
            temp += query(i + 1, j + 1, x - 1, y - 1);
            temp += (x - i - 1) - query(i + 1, j, x - 1, j);
            temp += (x - i - 1) - query(i + 1, y, x - 1, y);
            temp += (y - j - 1) - query(i, j + 1, i, y - 1);
            temp += (y - j - 1) - query(x, j + 1, x, y - 1);
            if (temp >= res) break;
            res = min(res, temp);
          }
    cout << res << endl;
  }
  return 0;
}

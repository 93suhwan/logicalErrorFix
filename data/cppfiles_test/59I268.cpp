#include <bits/stdc++.h>
using namespace std;
const int N = 1100;
int w[7][N];
int main() {
  int T;
  cin >> T;
  while (T--) {
    memset(w, 0, sizeof w);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= 5; j++) {
        int a;
        cin >> a;
        if (a == 1) {
          if (w[i][j] == 0) w[j][i] = 1, w[j][0]++;
        }
      }
    bool flag = 0;
    for (int i = 1; i < 5; i++)
      for (int j = i + 1; j <= 5; j++) {
        int k;
        if (w[i][0] < n / 2 || w[j][0] < n / 2) continue;
        for (k = 1; k <= n; k++) {
          if (!w[i][k] && !w[j][k]) {
            break;
          }
        }
        if (k == n + 1) flag = 1;
      }
    if (flag)
      cout << "YES";
    else
      cout << "NO";
    cout << endl;
  }
}

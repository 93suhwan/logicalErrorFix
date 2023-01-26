#include <bits/stdc++.h>
using namespace std;
int a[50010][6], minn[6];
int main() {
  int T, n;
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= 5; j++) {
        scanf("%d", &a[i][j]);
      }
    }
    int t = 1;
    for (int i = 2; i <= n; i++) {
      int ci = 0;
      for (int j = 1; j <= 5; j++) {
        if (a[i][j] < a[t][j]) ci++;
      }
      if (ci >= 3) t = i;
    }
    int key = 1;
    for (int i = 1; i <= n; i++) {
      if (i == t) continue;
      int ci = 0;
      for (int j = 1; j <= 5; j++) {
        if (a[i][j] < a[t][j]) ci++;
      }
      if (ci >= 3) {
        key = 0;
        break;
      }
    }
    if (key == 0)
      cout << -1 << endl;
    else
      cout << t << endl;
  }
  return 0;
}

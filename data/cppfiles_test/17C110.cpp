#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int r[n][5];
    for (int i = 0; i < n; i++)
      for (int j = 0; j < 5; j++) cin >> r[i][j];
    int max = 0;
    for (int i = 1; i < n; i++) {
      int num = 0;
      for (int j = 0; j < 5; j++)
        if (r[i][j] < r[max][j]) ++num;
      if (num >= 3) max = i;
    }
    int res = max;
    for (int i = 0; i < n; i++) {
      int num = 0;
      if (i != max) {
        for (int j = 0; j < 5; j++)
          if (r[i][j] < r[max][j]) ++num;
      }
      if (num >= 3) {
        res = -1;
        break;
      }
    }
    if (res == -1)
      cout << res << endl;
    else
      cout << max + 1 << endl;
  }
  return 0;
}

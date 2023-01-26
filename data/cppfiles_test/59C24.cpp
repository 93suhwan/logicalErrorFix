#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[n][5];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 5; j++) {
        cin >> arr[i][j];
      }
    }
    int cntd1 = 0;
    int cntd2 = 0;
    int common = 0;
    bool ok = 0;
    int ans = 0;
    for (int d1 = 0; d1 < 5; d1++) {
      for (int d2 = d1 + 1; d2 < 5; d2++) {
        cntd1 = 0, cntd2 = 0, common = 0;
        ok = 1;
        for (int i = 0; i < n; i++) {
          if (arr[i][d1] == 0 && arr[i][d2] == 0) ok = 0;
          if (arr[i][d1]) cntd1++;
          if (arr[i][d2]) cntd2++;
        }
        if (ok && cntd2 >= n / 2 && cntd1 >= n / 2) {
          ans = 1;
          break;
        }
      }
    }
    if (!ans)
      cout << "NO" << endl;
    else
      cout << "YES" << '\n';
  }
  return 0;
}

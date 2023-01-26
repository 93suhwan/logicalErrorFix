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
    for (int d1 = 0; d1 < 5; d1++) {
      for (int d2 = d1 + 1; d2 < 5; d2++) {
        for (int i = 0; i < n; i++) {
          if (arr[i][d1]) cntd1++;
          if (arr[i][d2]) cntd2++;
          if (arr[i][d1] && arr[i][d2]) common++;
        }
        if (cntd1 >= n / 2 && cntd2 >= n / 2 && cntd1 + cntd2 - common == n) {
          cout << "YES" << endl;
          ok = 1;
          continue;
        }
      }
    }
    if (!ok) cout << "NO" << endl;
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int tc;
  cin >> tc;
  while (tc > 0) {
    int flag = 0;
    int n;
    cin >> n;
    int arr[n][5];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 5; j++) cin >> arr[i][j];
    }
    for (int i = 0; i < 5; i++) {
      for (int j = i + 1; j < 5; j++) {
        int c1 = 0, c2 = 0, c3 = 0;
        for (int k = 0; k < n; k++) {
          if (arr[k][j] == 1 && arr[k][i] == 1)
            c3++;
          else if (arr[k][i] == 1)
            c1++;
          else if (arr[k][j] == 1)
            c2++;
        }
        int f = (n / 2) - c1, s = (n / 2) - c2;
        if (f >= 0 && s >= 0 && (f + s) == c3) {
          cout << "YES \n";
          flag = 1;
          break;
        }
      }
    }
    if (flag == 0) cout << "NO \n";
    --tc;
  }
}

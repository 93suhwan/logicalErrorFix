#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, flag = 0;
    cin >> n;
    char a[2][n];
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < n; j++) {
        cin >> a[i][j];
      }
    }
    for (int i = 1; i < n; i++) {
      if (a[0][i] == '1' and a[1][i] == '1') {
        flag = 1;
        break;
      }
    }
    if (flag == 0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}

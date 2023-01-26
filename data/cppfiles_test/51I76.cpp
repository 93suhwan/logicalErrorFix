#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int num;
    char cell[2][100];
    cin >> num;
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < num; j++) {
        cin >> cell[i][j];
      }
    }
    int tem = 0;
    for (int i = 0; i < num; i++) {
      if ((cell[0][i] == '1') && (cell[1][i] == '1')) {
        tem++;
        break;
      }
    }
    if (tem == 1) {
      cout << "NO" << endl;
    } else
      cout << "YES" << endl;
  }
  return 0;
}

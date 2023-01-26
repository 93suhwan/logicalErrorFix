#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[3][5000], b[7][5000], t;
  cin >> t;
  for (int i = 0; i != t; i++) {
    for (int j = 0; j != 7; j++) {
      cin >> b[j][i];
    }
    if (b[6][i] == (b[0][i] + b[1][i] + b[2][i])) {
      a[0][i] = b[0][i];
      a[1][i] = b[1][i];
      a[2][i] = b[2][i];
    } else if (b[6][i] == (b[0][i] + b[1][i] + b[3][i])) {
      a[0][i] = b[0][i];
      a[1][i] = b[1][i];
      a[2][i] = b[3][i];
    }
  }
  for (int i = 0; i != t; i++) {
    cout << a[0][i] << " " << a[1][i] << " " << a[2][i] << endl;
  }
  return 0;
}

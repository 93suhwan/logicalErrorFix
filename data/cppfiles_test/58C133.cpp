#include <bits/stdc++.h>
using namespace std;
long long int n, m;
char mat[2][101];
bool band;
int main() {
  cin >> n;
  band = true;
  while (n--) {
    cin >> m;
    for (int c = 0; c < 2; c++)
      for (int d = 0; d < m; d++) cin >> mat[c][d];
    for (int c = 0; c < m - 1; c++) {
      if (mat[0][c + 1] == '1' && mat[1][c + 1] == '1') {
        cout << "NO\n";
        band = false;
        break;
      }
    }
    if (band) cout << "YES\n";
    band = true;
  }
}

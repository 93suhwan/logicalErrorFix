#include <bits/stdc++.h>
using namespace std;
int main() {
  int k, t;
  cin >> t;
  while (t--) {
    cin >> k;
    int col = 1, ini = 1, m = 1;
    while (ini < k) {
      ini += m;
      col++;
      m += 2;
      if (ini + m > k) {
        break;
      }
    }
    int n = col;
    int row = 1;
    while (n-- > 1 && ini < k) {
      ini++;
      row++;
    }
    col -= (k - ini);
    cout << row << ' ' << col << endl;
  }
}

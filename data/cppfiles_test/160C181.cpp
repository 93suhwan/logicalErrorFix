#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int m;
    cin >> m;
    int pr, pc;
    cin >> pr >> pc;
    int dr, dc;
    cin >> dr >> dc;
    int step = 0;
    int moverow = 1;
    int movecolumn = 1;
    while (pr != dr && pc != dc) {
      if (pr == n) {
        moverow = 0;
      }
      if (pc == m) {
        movecolumn = 0;
      }
      if (moverow) {
        pr++;
      } else {
        pr--;
      }
      if (movecolumn) {
        pc++;
      } else {
        pc--;
      }
      step++;
      if (pr == dr || pc == dc) {
        break;
      }
    }
    cout << step << "\n";
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int t;
int main() {
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int rowe = 1, cole = 1;
    int row = 1, col = 1;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'R') {
        col++;
        if (col > m - cole + 1) break;
      } else if (s[i] == 'D') {
        row++;
        if (row > n - row + 1) break;
      } else if (s[i] == 'L') {
        col--;
        if (col <= 0) {
          col = 1;
          if (cole + 1 <= m)
            cole++;
          else
            break;
        }
      } else if (s[i] == 'U') {
        row--;
        if (row <= 0) {
          row = 1;
          if (rowe + 1 <= n)
            rowe++;
          else
            break;
        }
      }
    }
    cout << rowe << ' ' << cole << endl;
  }
  return 0;
}

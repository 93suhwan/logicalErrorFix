#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  unsigned long long t = 0;
  cin >> t;
  while (t--) {
    unsigned long long n, m, rc, cc, rd, cd;
    cin >> n >> m >> rc >> cc >> rd >> cd;
    if (rc <= rd && cc <= cd) {
      cout << min(rd - rc, cd - cc) << "\n";
    } else if (rc <= rd && cc >= cd) {
      cout << rd - rc << "\n";
    } else if (rc >= rd && cc <= cd) {
      cout << cd - cc << "\n";
    } else {
      int reached = 0, row = 0, col = 0, t = 0;
      while (reached == 0) {
        if (rc < n && rc != rd && row == 0)
          rc++;
        else {
          rc--;
          row = 1;
        }
        if (cc < m && cc != cd && col == 0)
          cc++;
        else {
          cc--;
          col = 1;
        }
        t++;
        if (rc == rd || cc == cd) {
          reached = 1;
          break;
        }
      }
      cout << t << "\n";
    }
  }
  return 0;
}

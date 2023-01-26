#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    long long int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    long long int xmax = 0, xmin = 0, ymax = 0, ymin = 0, xx = 1, yy = 1, i,
                  x = 0, y = 0;
    for (i = 0; i < s.length(); i++) {
      if (s[i] == 'U') {
        x--;
        xmax = max(xmax, x);
        xmin = min(xmin, x);
      }
      if (s[i] == 'D') {
        x++;
        xmax = max(xmax, x);
        xmin = min(xmin, x);
      }
      if (s[i] == 'R') {
        y++;
        ymax = max(ymax, y);
        ymin = min(ymin, y);
      }
      if (s[i] == 'L') {
        y--;
        ymax = max(ymax, y);
        ymin = min(ymin, y);
      }
      if (xmax - xmin < n and ymax - ymin < m)
        xx = 1 - xmin, yy = 1 - ymin;
      else
        break;
    }
    cout << xx << " " << yy << " "
         << " ";
    cout << "\n";
  }
  return 0;
}

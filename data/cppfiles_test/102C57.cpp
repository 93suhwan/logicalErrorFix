#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int m, n;
    string str;
    cin >> m >> n >> str;
    int minX = 0;
    int maxX = 0;
    int minY = 0;
    int maxY = 0;
    int cntX = 0;
    int cntY = 0;
    for (int i = 0; i < str.length(); i++) {
      if (str[i] == 'L')
        cntX--;
      else if (str[i] == 'R')
        cntX++;
      else if (str[i] == 'U')
        cntY--;
      else
        cntY++;
      minX = min(minX, cntX);
      maxX = max(maxX, cntX);
      minY = min(minY, cntY);
      maxY = max(maxY, cntY);
      if (maxX - minX >= n) {
        if (cntX == maxX) maxX--;
        break;
      }
      if (maxY - minY >= m) {
        if (cntY == maxY) maxY--;
        break;
      }
    }
    cout << m - maxY << " " << n - maxX << '\n';
  }
  return 0;
}

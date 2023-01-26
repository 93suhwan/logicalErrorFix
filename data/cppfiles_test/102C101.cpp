#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int deltaX = 0, deltaY = 0;
    int maxDeltaX = 0, minDeltaX = 0;
    int maxDeltaY = 0, minDeltaY = 0;
    int ansX = 1, ansY = 1;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == 'L') deltaY--;
      if (s[i] == 'R') deltaY++;
      if (s[i] == 'U') deltaX--;
      if (s[i] == 'D') deltaX++;
      minDeltaX = min(minDeltaX, deltaX);
      minDeltaY = min(minDeltaY, deltaY);
      maxDeltaX = max(maxDeltaX, deltaX);
      maxDeltaY = max(maxDeltaY, deltaY);
      int x = n - maxDeltaX;
      int y = m - maxDeltaY;
      if (x >= 1 and x <= n and x + minDeltaX >= 1 and x + maxDeltaX <= n and
          y >= 1 and y <= m and y + minDeltaY >= 1 and y + maxDeltaY <= m) {
        ansX = x;
        ansY = y;
      } else
        break;
    }
    cout << ansX << " " << ansY << endl;
  }
}

#include <bits/stdc++.h>
using namespace std;
int t, n;
string m[2];
int main() {
  cin >> t;
  while (t > 0) {
    t--;
    queue<pair<int, int> > q;
    cin >> n >> m[0] >> m[1];
    q.push({0, 0});
    while (q.size() > 0) {
      int x = q.front().first;
      bool y = q.front().second;
      if (x == n - 1 && y == 1) {
        break;
      }
      if (m[y][x + 1] == '0') {
        q.push({x + 1, y});
      }
      if (y == 0 && m[y + 1][x + 1] == '0') {
        q.push({x + 1, 1});
      }
      if (y == 1 && m[y - 1][x + 1] == '0') {
        q.push({x + 1, 0});
      }
      q.pop();
    }
    if (q.front().first == n - 1 && q.front().second == 1) {
      cout << "YES";
    } else {
      cout << "NO";
    }
    cout << endl;
  }
  return 0;
}

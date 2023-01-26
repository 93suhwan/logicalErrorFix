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
    int x = 1, y = 1;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'L' && x < n) x++;
      if (s[i] == 'R' && x > 0) x--;
      if (s[i] == 'U' && y < m) y++;
      if (s[i] == 'D' && y > 0) y--;
    }
    cout << x << " " << y << endl;
  }
}

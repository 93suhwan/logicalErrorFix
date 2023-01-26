#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int x = 0, y = 0, z = 0, v;
  string w;
  cin >> v;
  while (v--) {
    cin >> w;
    for (int i = 0; i < w.length(); i++) {
      if (w[i] == 'A')
        x++;
      else if (w[i] == 'B')
        y++;
      else
        z++;
    }
    if (y == x + z)
      cout << "YES"
           << "\n";
    else
      cout << "NO\n";
    x = y = z = 0;
  }
}

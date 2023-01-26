#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int x, y, z;
  string w;
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
}

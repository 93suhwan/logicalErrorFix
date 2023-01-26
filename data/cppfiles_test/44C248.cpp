#include <bits/stdc++.h>
using namespace std;
void sol() {
  int x, y;
  cin >> x >> y;
  if (abs(x) % 2 != abs(y) % 2)
    cout << "-1\n";
  else if (x == 0 && y == 0)
    cout << "0\n";
  else if (abs(x) == abs(y))
    cout << "1\n";
  else
    cout << "2\n";
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) sol();
  return 0;
}

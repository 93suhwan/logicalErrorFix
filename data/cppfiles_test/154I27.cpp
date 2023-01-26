#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int x, y, z;
    cin >> x >> y >> z;
    if ((x + y + z) % 4 == 0 || (x + y + z) % 4 == 2)
      cout << "YES";
    else
      cout << "NO";
    cout << endl;
  }
}

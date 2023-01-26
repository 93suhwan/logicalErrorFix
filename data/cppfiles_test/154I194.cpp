#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int x, y, z;
    cin >> x >> y >> z;
    if ((x + y + z) % 2 == 0)
      cout << "YES";
    else
      cout << "NO";
    cout << endl;
  }
}

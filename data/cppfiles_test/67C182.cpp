#include <bits/stdc++.h>
const int inf = 0x3f3f3f3f;
const int N = 1e8 + 10;
using namespace std;
int a, b, c;
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> a >> b >> c;
    int z = abs(a - b) + 1;
    int minn = min(a, b);
    int maxn = max(a, b);
    if (a == 1 && b == 2 || a == 2 && b == 1) {
      if (c == 1)
        cout << "2" << endl;
      else if (c == 2)
        cout << "1" << endl;
      else
        cout << "-1" << endl;
    } else {
      if (((z <= minn || z >= maxn) && minn != 1) || (c > z * 2 - 2)) {
        cout << "-1" << endl;
        continue;
      }
      if (c >= z)
        cout << c - z + 1 << endl;
      else
        cout << c - 1 + z << endl;
    }
  }
}

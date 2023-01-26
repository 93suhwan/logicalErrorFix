#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a;
  cin >> a;
  while (a--) {
    long long x, z, y;
    cin >> x >> z >> y;
    if (x != z && z != y) {
      if (x > z && x > y) {
        if (x - y == z)
          cout << "YES" << endl;
        else
          cout << "NO" << endl;
      } else if (z > x && z > y) {
        if (z - x == y)
          cout << "YES" << endl;
        else
          cout << "NO";
      } else {
        if (y - x == z)
          cout << "YES" << endl;
        else
          cout << "NO" << endl;
      }
    } else if (x == y && x != z) {
      if (z % 2 == 0)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    } else if (x == z && z != y) {
      if (y % 2 == 0)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    } else if (z == y && z != x) {
      if (x % 2 == 0)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    } else {
      if (x % 2 == 0)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
  }
}

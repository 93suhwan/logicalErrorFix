#include <bits/stdc++.h>
using namespace std;
int main() {
  int _TC_;
  cin >> _TC_;
  while (_TC_--) {
    int x, y;
    cin >> x >> y;
    if (max(x, y) % min(x, y) == 0) {
      cout << min(x, y) << endl;
      continue;
    }
    if (x > y) {
      cout << x + y << endl;
      continue;
    }
    cout << (y + (y / x * x)) / 2 << endl;
  }
}

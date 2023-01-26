#include <bits/stdc++.h>
using namespace std;
int t;
long long x, y;
int main() {
  cin >> t;
  while (t--) {
    cin >> x >> y;
    if (x <= y)
      cout << (x + y) / 2 << endl;
    else
      cout << x + y << endl;
  }
}

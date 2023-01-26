#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long c, d;
    cin >> c >> d;
    if (c + d == 0)
      cout << "0" << endl;
    else if (abs(c - d) % 2 == 1)
      cout << "-1" << endl;
    else if (c == d)
      cout << "1" << endl;
    else
      cout << "2" << endl;
  }
}

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int c, d;
    cin >> c >> d;
    if (c < 0) c = -c;
    if (d < 0) d = -d;
    if (c == 0 && d == 0) {
      cout << "0\n";
      continue;
    }
    if (c < d) swap(c, d);
    if ((c - d) % 2)
      cout << "-1\n";
    else if (c == d)
      cout << "1\n";
    else
      cout << "2\n";
  }
  return 0;
}

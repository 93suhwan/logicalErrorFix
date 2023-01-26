#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  while (n--) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a > b) {
      int s = a;
      a = b;
      b = s;
    }
    int s = b - a;
    int maxn = 2 * s;
    if (b >= 2 * a && c <= maxn) {
      if (c > maxn / 2)
        cout << c - s << endl;
      else
        cout << c + s << endl;
    } else
      cout << -1 << endl;
  }
  return 0;
}

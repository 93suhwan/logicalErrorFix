#include <bits/stdc++.h>
using namespace std;
int t, a, b, c;
int main() {
  cin >> t;
  while (t--) {
    cin >> a >> b >> c;
    if (a < b) swap(a, b);
    int d = (a - b) * 2;
    int mid = 1 + a - b;
    if ((a - mid) * (b - mid) > 0 || d == 2 || c > d || (a - b + 1) == b)
      cout << -1 << endl;
    else {
      if (c >= (a - b + 1))
        cout << c - (a - b) << endl;
      else if (c < a - b + 1)
        cout << c + (a - b) << endl;
    }
  }
  return 0;
}

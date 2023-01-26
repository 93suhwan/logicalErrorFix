#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int TC;
  cin >> TC;
  while (TC--) {
    long long X, Y;
    cin >> X >> Y;
    if (X == Y)
      cout << X << "\n";
    else if (Y < X)
      cout << X + Y << "\n";
    else {
      if (Y % X == 0)
        cout << X << "\n";
      else {
        long long h = (Y + X) / 2;
        long long G = Y - h;
        long long T = Y % X;
        if (G < X)
          cout << h << "\n";
        else
          cout << Y - T / 2 << "\n";
      }
    }
  }
  return 0;
}

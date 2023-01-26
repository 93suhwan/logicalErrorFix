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
        long long M = h % X;
        long long T = Y % h;
        long long K = (M + T) / 2;
        if (K == X)
          cout << h - M << "\n";
        else
          cout << h + K - M << "\n";
      }
    }
  }
  return 0;
}

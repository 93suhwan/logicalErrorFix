#include <bits/stdc++.h>
using namespace std;
int main() {
  int a;
  cin >> a;
  for (int i = 0; i < a; i++) {
    long long b;
    cin >> b;
    long long all = sqrt(b);
    if (b == 1) {
      cout << 1 << " " << 1 << endl;
    } else if (all * all == b) {
      cout << all << " " << 1 << endl;
    } else {
      all++;
      long long c = (all * all) - ((all - 1) * (all - 1));
      long long x, y;
      if (b - (all - 1) * (all - 1) <= c / 2) {
        x = all;
        y = b - (all - 1) * (all - 1);
      } else if (b - (all - 1) * (all - 1) == c / 2 + 1) {
        y = all;
        x = all;
      } else {
        y = all;
        x = c - (b - (all - 1) * (all - 1)) + 1;
      }
      cout << y << " " << x << endl;
    }
  }
}

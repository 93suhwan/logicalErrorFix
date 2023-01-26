#include <bits/stdc++.h>
using namespace std;
const int T = 1000000000;
void print(int x, int y) { cout << "? " << x << " " << y << endl; }
int main() {
  int L = 1, R = T, x;
  int t1, t2;
  print(L, 1);
  cin >> x;
  t1 = x;
  print(R, 1);
  cin >> x;
  t2 = x;
  while (L <= R) {
    int mid = (L + R) >> 1;
    print(mid, 1);
    cin >> x;
    if (x == -1) return 0;
    if (t1 - (mid - L) == x)
      L = mid;
    else if (t2 - (R - mid) == x)
      R = mid;
    else {
      int l = L + t1 - x;
      int r = R - (t2 - x);
      int d = x + 1;
      print(d, T);
      cin >> x;
      if (x == -1) return 0;
      int u = T - x;
      cout << "! " << l << " " << d << " " << r << " " << u << endl;
      return 0;
    }
  }
  return 0;
}

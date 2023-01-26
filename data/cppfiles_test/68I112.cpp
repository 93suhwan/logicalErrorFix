#include <bits/stdc++.h>
using namespace std;
void fun() {
  int k;
  cin >> k;
  int iter = sqrt(k);
  if (iter * iter == k) {
    cout << iter << " " << 1 << endl;
    return;
  }
  int x = iter + 1;
  int y = k - (x - 1) * (x - 1);
  if (x > y) {
    cout << y << " " << x << endl;
    return;
  }
  y = iter + 1;
  x = (y - 1) * (y - 1) + 2 * y - k;
  if (x < y) {
    cout << y << " " << x << endl;
    return;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    fun();
  }
}

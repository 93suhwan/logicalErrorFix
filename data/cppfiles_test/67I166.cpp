#include <bits/stdc++.h>
using namespace std;
int ans(int a, int b, int c) {
  if (c >= 2 * abs(a - b) || abs(a - b) == 1) {
    return -1;
  }
  if (c > abs(a - b)) return c - abs(a - b);
  return c + abs(a - b);
}
int main() {
  int nt;
  cin >> nt;
  while (nt--) {
    int a, b, c;
    cin >> a;
    cin >> b;
    cin >> c;
    cout << ans(a, b, c) << endl;
  }
  return 0;
}

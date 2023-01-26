#include <bits/stdc++.h>
using namespace std;
int query(int x, int y) {
  int res;
  cout << "? " << x << " " << y << endl;
  cout.flush();
  cin >> res;
  return res;
}
int main() {
  int a = query(1, 1);
  int b = query(1, 1000000000);
  int c = query(1000000000, 1);
  int x = (1000000000 + 1 + a - b) / 2;
  int y = (1000000000 + 1 + a - c) / 2;
  int l = query(1, x) + 1, r = 1000000000 - query(1000000000, x);
  int d = query(y, 1) + 1, u = 1000000000 - query(y, 1000000000);
  printf("! %d %d %d %d", l, d, r, u);
  return 0;
}

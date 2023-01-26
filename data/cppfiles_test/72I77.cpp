#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e9;
int query(int a, int b) {
  int x;
  cout << "? " << a << " " << b << endl;
  cin >> x;
  return x;
}
int main() {
  int x, y;
  x = query(1, 1);
  y = query(MAX, 1);
  int i = (MAX + 1 + x - y) / 2;
  int j = x + 2 - i;
  if (j < 1) j = 1;
  int c1 = 1 + query(i, j);
  int l1 = x + 2 - c1;
  int l2 = c1 + (MAX - y - 1);
  int c2 = MAX - query(i, MAX);
  cout << "! " << l1 << " " << c1 << " " << l2 << " " << c2 << endl;
  return 0;
}

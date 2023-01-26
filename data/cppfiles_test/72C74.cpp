#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9;
int main() {
  int d1, d2, d3, d4, d5;
  cout << "? 1 1" << endl;
  cin >> d1;
  cout << "? 1 " << mod << endl;
  cin >> d2;
  cout << "? " << mod << " " << mod << endl;
  cin >> d3;
  cout << "? " << mod << " 1" << endl;
  cin >> d4;
  int m = (d1 + 1 + mod - d4) / 2;
  cout << "? " << m << " 1" << endl;
  cin >> d5;
  int x, y, p, q;
  x = d1 - d5 + 1;
  y = d5 + 1;
  p = mod - (d4 - d5);
  q = mod - (d3 - (d4 - d5));
  cout << "! " << x << " " << y << " " << p << " " << q << endl;
  return 0;
}

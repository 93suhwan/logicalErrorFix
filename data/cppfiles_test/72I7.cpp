#include <bits/stdc++.h>
using namespace std;
const long long N = 1e9;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long d1, d2, d3, d4, x, y, p, q;
  cout << "? 1 1" << endl;
  cin >> d1;
  cout << "? 1 " << N << endl;
  cin >> d2;
  long long ym = (d1 + d2 - 1) / 2;
  cout << "? 1 " << ym << endl;
  cin >> d3;
  cout << "? " << N << " " << ym << endl;
  cin >> d4;
  x = 1 + d3;
  y = 2 + d1 - x;
  p = N - d4;
  q = N - d2 + x;
  cout << "! " << x << " " << y << " " << p << " " << q << endl;
  return 0;
}

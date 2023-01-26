#include <bits/stdc++.h>
using namespace std;
const int s = 1e9;
int main() {
  int ul, ur, bl, br;
  cout << "? 1 1" << endl;
  cin >> bl;
  cout << "? 1000000000 1" << endl;
  cin >> br;
  cout << "? 1 1000000000" << endl;
  cin >> ul;
  cout << "? 1000000000 1000000000" << endl;
  cin >> ur;
  int mid = bl + (s - br);
  mid /= 2;
  int dist;
  cout << "? " << mid << " 1" << endl;
  cin >> dist;
  int xm = bl - dist + 1;
  int ym = dist + 1;
  int xx = s - (br - dist);
  int yx = s - ur - xx + s;
  cout << "! " << xm << " " << ym << " " << xx << " " << yx << endl;
}

#include <bits/stdc++.h>
using namespace std;
long long dis1, dis2, dis3, dis4, lx, ly, rx, ry;
const long long INF = 1000000000;
int main() {
  cout << "? 1 1" << endl;
  cin >> dis1;
  cout << "? 1 1000000000" << endl;
  cin >> dis2;
  cout << "? 1000000000 1000000000" << endl;
  cin >> dis3;
  cout << "? 1000000000 1" << endl;
  cin >> dis4;
  if (dis1 + dis2 <= INF)
    cout << "? 1 " << dis1 << endl;
  else
    cout << "? 1 " << (dis1 + INF - dis2) / 2 << endl;
  cin >> lx;
  if (dis1 + dis4 <= INF)
    cout << "? " << dis1 << " 1" << endl;
  else
    cout << "? " << (dis1 + INF - dis4) / 2 << " 1" << endl;
  cin >> ly;
  if (dis2 + dis3 <= INF)
    cout << "? " << dis2 << " 1000000000" << endl;
  else
    cout << "? " << (dis2 + INF - dis3) / 2 << " 1000000000" << endl;
  cin >> rx;
  if (dis2 + dis3 <= INF)
    cout << "? 1000000000 " << dis4 << endl;
  else
    cout << "? 1000000000 " << (dis4 + INF - dis3) / 2 << endl;
  cin >> ry;
  printf("! %lld %lld %lld %lld", lx + 1, ly + 1, 1000000000 - rx - 1,
         1000000000 - ry - 1);
  cout << endl;
  return 0;
}

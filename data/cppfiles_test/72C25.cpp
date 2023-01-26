#include <bits/stdc++.h>
const long long mod = 1e9 + 7;
const long long MAX = INT_MAX;
const long long inf = LLONG_MAX;
const double pi = 3.14159265358979323846;
long long dirX[] = {1, -1, 0, 0};
long long dirY[] = {0, 0, 1, -1};
using namespace std;
void print_bool(bool zeman_modnar) {
  if (zeman_modnar)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
int32_t main() {
  long long val = 1e9;
  cout << "? 1 1" << endl;
  long long bottomleft;
  cin >> bottomleft;
  cout << "? 1 " << val << endl;
  long long topleft;
  cin >> topleft;
  long long X = bottomleft - topleft;
  long long midrange = (val + X) / 2;
  cout << "? 1 " << midrange << endl;
  long long lx;
  cin >> lx;
  long long ly = bottomleft - lx;
  lx++;
  ly++;
  cout << lx << " " << ly << endl;
  cout << "? " << val << " " << val << endl;
  long long topright;
  cin >> topright;
  cout << "? " << val << " " << 1 << endl;
  long long bottomright;
  cin >> bottomright;
  X = topright - bottomright;
  midrange = (val + X) / 2;
  cout << "? " << val << " " << val - midrange << endl;
  long long valreq;
  cin >> valreq;
  long long dely = topright - valreq;
  long long rx = val - valreq;
  long long ry = val - dely;
  cout << "! " << lx << " " << ly << " " << rx << " " << ry << endl;
  return 0;
}

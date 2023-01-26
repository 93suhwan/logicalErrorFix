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
  long long midrange = (val + X + 1) / 2;
  long long l = 1, r = midrange;
  cout << "? 1 " << r << endl;
  long long valreq;
  cin >> valreq;
  long long ans;
  while (l <= r) {
    long long mid = (l + r) / 2;
    cout << "? 1 " << mid << endl;
    long long pos;
    cin >> pos;
    if (pos == valreq) {
      r = mid - 1;
      ans = mid;
    } else {
      l = mid + 1;
    }
  }
  long long bly = ans;
  long long blx = bottomleft - (bly - 1) + 1;
  cout << "? " << val << " " << val << endl;
  long long topright;
  cin >> topright;
  cout << "? " << val << " " << 1 << endl;
  long long bottomright;
  cin >> bottomright;
  X = topright - bottomright;
  midrange = (val + X + 1) / 2;
  l = val - midrange;
  r = val;
  ans = -1;
  cout << "? " << val << " " << val - midrange << endl;
  cin >> valreq;
  while (l <= r) {
    long long mid = (l + r) / 2;
    cout << "? " << val << " " << mid << endl;
    long long pos;
    cin >> pos;
    if (pos == valreq) {
      ans = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  long long ry = ans;
  long long rx = (topright - 2 * val + ry);
  cout << "! " << blx << " " << bly << " " << -1 * rx << " " << ry << endl;
  return 0;
}

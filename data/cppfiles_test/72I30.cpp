#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
const int N = 2e5 + 5;
const long long int mod = 1e9 + 7;
const long long int Mod = 998244353;
const long double Pi = acos(-1);
const long long int Inf = 4e18;
const long double Eps = 1e-9;
int dx[9] = {0, 1, -1, 0, 0, 1, 1, -1, -1};
int dy[9] = {0, 0, 0, 1, -1, 1, -1, 1, -1};
using namespace std;
int Query(int x, int y) {
  cout << "? " << x << " " << y << endl;
  int ret;
  cin >> ret;
  return ret;
}
void TestCase() {
  int big = 1e9, z1 = Query(1, 1), z2 = Query(1, big), lb = 1, ub = big, x, y,
      p, q;
  if (z1 > z2) {
    lb = 1 + z1 - z2;
  } else if (z1 < z2) {
    ub = big + z1 - z2;
  }
  int l = lb, r = ub;
  ub = (lb + ub) / 2;
  y = ub;
  ub--;
  while (lb <= ub) {
    int mid = (lb + ub) >> 1;
    int a = Query(1, mid), b = Query(1, mid + 1);
    if (a > b)
      lb = mid + 1;
    else {
      y = min(y, mid);
      ub = mid - 1;
    }
  }
  x = z1 - y + 2;
  q = l + r - y;
  int ret = Query(big, y);
  p = big - ret;
  cout << "! " << x << " " << y << " " << p << " " << q << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  int T = 1;
  while (T--) {
    TestCase();
    cout << "\n";
  }
  return 0;
}

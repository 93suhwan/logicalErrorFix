#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int tc;
  cin >> tc;
  for (long long int i = 0; i < tc; i++) {
    long long int res = 0, res1 = 0, mex, xr, x;
    cin >> mex >> xr;
    x = (mex - 1) % 4;
    if (x == 0)
      res = mex - 1;
    else if (x == 1)
      res = 1;
    else if (x == 2)
      res = mex;
    else
      res = 0;
    res1 = res ^ mex;
    if (res == xr)
      cout << mex << endl;
    else if (res1 == xr)
      cout << mex + 2 << endl;
    else
      cout << mex + 1 << endl;
  }
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; i++) {
    int res = 0, res1 = 0, mex, xr;
    cin >> mex >> xr;
    for (int j = 0; j < mex; j++) res = res ^ j;
    res1 = res ^ mex;
    if (res == xr)
      cout << mex;
    else if (res1 == xr)
      cout << mex + 2;
    else
      cout << mex + 1;
  }
}

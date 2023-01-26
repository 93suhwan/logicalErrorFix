#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
const int N = 4e5 + 5;
signed main() {
  4;
  cin.tie(nullptr)->sync_with_stdio(false);
  ll tc = 1;
  cin >> tc;
  while (tc--) {
    ll mex, x;
    cin >> mex >> x;
    mex--;
    if (mex % 4 == 0)
      x ^= mex;
    else if (mex % 4 == 1)
      x ^= 1;
    else if (mex % 4 == 2)
      x ^= (mex + 1);
    else
      x ^= 0;
    mex++;
    if (x) {
      if (x == mex)
        cout << mex + 2 << '\n';
      else
        cout << mex + 1 << '\n';
    } else {
      cout << mex << '\n';
    }
  }
}

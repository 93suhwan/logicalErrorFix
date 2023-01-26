#include <bits/stdc++.h>
using namespace std;
long long T, a, b, c, mn, mx;
int32_t main() {
  cin >> T;
  while (T--) {
    cin >> a >> b >> c;
    long long subb = abs(a - b);
    long long mrkz = 1 + subb;
    long long akbr = mrkz - 1 + subb;
    if (c > akbr)
      cout << -1 << endl;
    else if (a >= mrkz && b >= mrkz)
      cout << -1 << endl;
    else if (a < mrkz && b < mrkz)
      cout << -1 << endl;
    else {
      long long jj = (c + subb) % akbr;
      if (jj == 0) jj = akbr;
      if (c < mrkz && jj >= mrkz)
        cout << jj << endl;
      else if (c >= mrkz && jj < mrkz)
        cout << jj << endl;
      else
        cout << -1 << endl;
    }
  }
}

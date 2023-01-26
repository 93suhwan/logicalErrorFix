#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t;
  cin >> t;
  while (t--) {
    long long mex, xor_;
    cin >> mex >> xor_;
    if (xor_ == 0) {
      if (mex % 4 == 3)
        cout << mex + 2 << endl;
      else if (mex % 4 == 0)
        cout << mex << endl;
      else
        cout << mex + 1 << endl;
    } else if (xor_ == 1) {
      if (mex % 4 == 1)
        cout << mex + 2 << endl;
      else if (mex % 4 == 2)
        cout << mex << endl;
      else
        cout << mex + 1 << endl;
    } else if (xor_ % 4 == 0) {
      if (mex % 4 == 0)
        cout << mex + 2 << endl;
      else
        cout << mex + 1 << endl;
    } else if (xor_ % 4 == 3) {
      if (mex % 4 == 2)
        cout << mex + 2 << endl;
      else
        cout << mex + 1 << endl;
    }
  }
  return 0;
}

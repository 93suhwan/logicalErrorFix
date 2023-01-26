#include <bits/stdc++.h>
using namespace std;
signed main(void) {
  register long long Case;
  cin >> Case;
  while (Case--) {
    register long long N;
    cin >> N;
    if (N <= 6)
      cout << 15 << endl;
    else if (N & 1)
      cout << (N + 1) / 2 * 5 << endl;
    else
      cout << N / 2 * 5 << endl;
  }
  return 0;
}

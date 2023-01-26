#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long x0, n;
    cin >> x0 >> n;
    vector<long long> sd(4);
    long long tmp = x0;
    for (long long i = 0; i < 4; i++) {
      if (x0 & 1)
        x0 += (i + 1);
      else
        x0 -= (i + 1);
      sd[i] = x0;
    }
    if (n % 4 == 0) {
      cout << sd[3];
    } else if (n % 4 == 1) {
      long long ds = (n - 1) / 4;
      if (tmp & 1)
        cout << sd[0] + ds * 4;
      else
        cout << sd[0] - ds * 4;
    } else if (n % 4 == 2) {
      cout << sd[1];
    } else {
      long long ds = (n - 1) / 4;
      if (tmp & 1)
        cout << sd[2] - ds * 4;
      else
        cout << sd[2] + ds * 4;
    }
    cout << endl;
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long k, r, c;
    cin >> k;
    double temp;
    temp = sqrt(k);
    if (temp != (int)temp) {
      r = temp + 1;
      c = (r * r) - k + 1;
    } else {
      r = temp;
      c = 1;
    }
    cout << r << ' ' << c << endl;
  }
}

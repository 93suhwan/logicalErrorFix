#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int k, row = 0, col = 0, d, diff;
    cin >> k;
    d = abs((sqrt(k)));
    diff = k - (d * d);
    if (diff == 0) {
      row = d;
      col = 1;
    } else {
      if (diff <= d + 1) {
        col = d + 1;
        row = diff;
      } else {
        diff -= d + 1;
        row = d + 1;
        col = d + 1 - diff;
      }
    }
    cout << row << " " << col << endl;
  }
  return 0;
}

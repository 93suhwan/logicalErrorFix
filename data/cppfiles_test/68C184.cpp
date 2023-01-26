#include <bits/stdc++.h>
using namespace std;
long long int findNearest(long long int k) {
  long long int sr = sqrt(k);
  long long int a = sr * sr;
  long long int b = (sr + 1) * (sr + 1);
  if ((k - a) < (b - k))
    return a;
  else
    return b;
}
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int k, diff, row, clmn;
    cin >> k;
    long long int x = findNearest(k);
    if (x < k) {
      diff = k - x;
      if (diff == sqrt(x)) {
        row = sqrt(x);
        clmn = diff + 1;
      } else {
        row = diff;
        clmn = sqrt(x) + 1;
      }
    } else {
      diff = x - k;
      if (diff != sqrt(x)) {
        row = sqrt(x);
        clmn = diff + 1;
      } else {
        row = diff;
        clmn = sqrt(x) + 1;
      }
    }
    cout << row << " " << clmn << endl;
  }
}

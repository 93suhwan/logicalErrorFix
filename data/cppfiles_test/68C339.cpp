#include <bits/stdc++.h>
bool sq(int n) {
  if (n >= 0) {
    long long sr = sqrt(n);
    return (sr * sr == n);
  }
  return false;
}
using namespace std;
int main() {
  int t, n;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n;
    if (sq(n)) {
      int r, c;
      r = pow(n, 0.5);
      c = 1;
      cout << r << " " << c << endl;
    } else {
      int k = (pow(n, 0.5));
      int d = n - (k * k);
      int r, c;
      r = c = k;
      if (d <= (k + 1)) {
        c++;
        r = d;
      } else {
        int e = d - (k + 1);
        r++;
        c = k - (e - 1);
      }
      cout << r << " " << c << endl;
    }
  }
}

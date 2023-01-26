#include <bits/stdc++.h>
using namespace std;
int countsq(int n) { return floor(sqrt(n)); }
int countcb(int n) { return floor(cbrt(n)); }
int countcommon(int n) {
  int a = floor(cbrt(n));
  return floor(sqrt(a));
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a = countsq(n);
    int b = countcb(n);
    int c = countcommon(n);
    cout << a + b - c << endl;
  }
  return 0;
}

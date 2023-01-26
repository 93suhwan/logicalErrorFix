#include <bits/stdc++.h>
using namespace std;
int power(int x, int y) {
  int res = 1;
  while (y) {
    if (y % 2 == 1) res = (res * x);
    y = y >> 1;
    x = (x * x);
  }
  return res;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int a1 = 0, a0 = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] == 1) a1++;
      if (a[i] == 0) a0++;
    }
    int s = 0;
    for (int i = 0; i < n; i++) {
      s += a[i];
    }
    cout << (a1 * power(2, a0));
    cout << endl;
  }
  return 0;
}

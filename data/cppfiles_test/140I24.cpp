#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    double a = floor(pow(n, 1.0 / 2.0));
    if (pow(n, 1.0 / 2.0) - floor(pow(n, 1.0 / 2.0)) > 0.99999) {
      a++;
    }
    double b = floor(pow(n, 1.0 / 3.0));
    if (pow(n, 1.0 / 3.0) - floor(pow(n, 1.0 / 2.0)) > 0.99999) {
      b++;
    }
    double c = floor(pow(n, 1.0 / 6.0));
    if (pow(n, 1.0 / 6.0) - floor(pow(n, 1.0 / 6.0)) > 0.99999) {
      c++;
    }
    cout << a + b - c << endl;
  }
  return 0;
}

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
    double a = sqrt(n);
    double b = pow(n, 1.0 / 3.0);
    cout << floor(a) + floor(b) - 1 << endl;
  }
  return 0;
}

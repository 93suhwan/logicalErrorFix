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
    int a = floor(sqrt(n));
    int b = floor(pow(n, 1.0 / 3.0));
    int c = floor(pow(n, 1.0 / 6.0));
    cout << a + b - c << endl;
  }
  return 0;
}

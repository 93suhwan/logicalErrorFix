#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long res = 0;
    res = floor(sqrt(n)) + floor(cbrt(n));
    long long i = 1;
    while (pow(i, 6) <= n) {
      res--;
      i++;
    }
    cout << res << endl;
  }
}

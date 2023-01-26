#include <bits/stdc++.h>
using namespace std;
int modInverse(int a, int m) {
  int m0 = m;
  int y = 0, x = 1;
  if (m == 1) return 0;
  while (a > 1) {
    int q = a / m;
    int t = m;
    m = a % m, a = t;
    t = y;
    y = x - q * y;
    x = t;
  }
  if (x < 0) x += m0;
  return x;
}
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    while (n--) cout << "()";
    cout << "\n";
    ;
  }
}

#include <bits/stdc++.h>
using namespace std;
long long int power(long long int x, long long int y, long long int z) {
  if (y == 0)
    return 1;
  else {
    long long int p = power(x, y / 2, z);
    long long int w = (p * p) % z;
    if (y % 2 == 0)
      return w;
    else
      return (x * w) % z;
  }
}
long long int gcd(long long int x, long long int y) {
  if (y == 0)
    return x;
  else
    return gcd(y, x % y);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(20);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) cout << "()";
      for (int j = 0; j < (2 * n - 2 * i) / 2; j++) cout << "(";
      for (int j = 0; j < (2 * n - 2 * i) / 2; j++) cout << ")";
      cout << "\n";
    }
  }
}

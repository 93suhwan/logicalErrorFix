#include <bits/stdc++.h>
using namespace std;
long long factorial(long long n) {
  if (n == 0 || n == 1) return 1;
  return n * factorial(n - 1);
}
long long combination(long long n, long long r) {
  return factorial(n) / (factorial(n - r) * factorial(r));
}
long long permutation(long long n, long long r) {
  return combination(n, r) * factorial(r);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    long long x, n;
    cin >> x >> n;
    if (abs(x) % 2 == 0) {
      if (n % 4 == 1) {
        cout << x - n << '\n';
      } else if (n % 4 == 2) {
        cout << 1 + x << '\n';
      } else if (n % 4 == 3) {
        cout << 4 * (n / 4) + 4 + x << '\n';
      } else {
        cout << x << '\n';
      }
    } else {
      if (n % 4 == 1) {
        cout << x + n << '\n';
      } else if (n % 4 == 2) {
        cout << 0 << '\n';
      } else if (n % 4 == 3) {
        cout << x - 4 * ((n + 1) / 4) << '\n';
      } else {
        cout << x << '\n';
      }
    }
  }
  return 0;
}

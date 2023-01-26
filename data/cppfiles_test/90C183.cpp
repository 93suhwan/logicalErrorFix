#include <bits/stdc++.h>
using namespace std;
mt19937 gen(time(0));
long long gcd(long long a, long long b) {
  while (b != 0) {
    a %= b;
    swap(a, b);
  }
  return a;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long t, x, y, n;
  cin >> t;
  while (t--) {
    cin >> x >> y;
    if (x > y) {
      cout << x + y << "\n";
      continue;
    }
    if (y % x == 0) {
      cout << x << "\n";
      continue;
    }
    n = y / x * x + y % x / 2;
    cout << n << "\n";
  }
}

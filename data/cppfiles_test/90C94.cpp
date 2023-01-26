#include <bits/stdc++.h>
using namespace std;
unsigned long long n, x, y, t;
unsigned long long solve() {
  if (y % x == 0) return x;
  if (x > y) return x + y;
  unsigned long long z = x * (y / x);
  return (z + y) / 2;
}
int main() {
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> x >> y;
    cout << solve() << endl;
  }
  return 0;
}

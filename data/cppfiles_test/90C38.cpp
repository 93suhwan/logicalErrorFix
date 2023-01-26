#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 7;
bool pri(int a) {
  if (a == 1) return 0;
  for (int i = 2; i * i <= a; i++) {
    if (a % i == 0) {
      return 0;
    }
  }
  return 1;
}
long long n, m, t, a[200000];
string s;
int main() {
  cin >> t;
  while (t--) {
    long long x, y;
    cin >> x >> y;
    if (x > y) {
      cout << x + y << "\n";
      continue;
    }
    if (x == y) {
      cout << x << "\n";
      continue;
    }
    if (2 * x >= y) {
      cout << (x + y) / 2 << "\n";
      continue;
    }
    x = x * int(y / x);
    cout << (x + y) / 2 << "\n";
  }
  return 0;
}

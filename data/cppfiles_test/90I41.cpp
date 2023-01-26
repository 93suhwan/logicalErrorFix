#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (a % b == 0)
    return b;
  else
    return gcd(b, a % b);
}
void solve() {
  long long x, y;
  scanf("%d%d", &x, &y);
  if (x <= y) {
    if (y % x == 0)
      cout << x << endl;
    else if ((y - x) % 2 == 0)
      cout << (y - x) / 2 + x << endl;
    else {
      for (int i = x + 1; i < y; i++) {
        if (i % x == y % i) {
          cout << i << endl;
          break;
        }
      }
    }
  } else
    cout << x * y + y << endl;
  long long n;
  return;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

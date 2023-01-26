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
  long long n = 0;
  if (x <= y) {
    if (y % x == 0) {
      n = x;
    } else if ((y - x) % 2 == 0) {
      n = (y - x) / 2 + x;
    } else {
      for (int i = x + 1; i < y && n == 0; i++) {
        if (i % x == y % i) {
          n = i;
        }
      }
    }
  } else {
    n = x * y + y;
  }
  cout << n << endl;
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

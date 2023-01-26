#include <bits/stdc++.h>
using namespace std;
bool jug(bool u, long long v) {
  if (v % 2) return !u;
  return u;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long x, n, sum = 0;
    cin >> x >> n;
    if (n % 4 == 1) {
      sum = n;
    }
    if (n % 4 == 2) {
      sum = -1;
    }
    if (n % 4 == 3) {
      sum = -n - 1;
    }
    if (x % 2)
      x += sum;
    else
      x -= sum;
    cout << x << endl;
  }
  return 0;
}

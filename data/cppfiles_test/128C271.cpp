#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  if (n % 2 == 0) {
    long long x = (n / 2);
    if (x % 2 == 0)
      cout << x << " " << x - 2 << " " << 2 << endl;
    else
      cout << x << " " << x - 1 << " " << 1 << endl;
  } else {
    int x = n - 1;
    int y = (x / 2);
    if (y % 2 == 0)
      cout << y + 1 << " " << y - 1 << " " << 1 << endl;
    else
      cout << y + 2 << " " << y - 2 << " " << 1 << endl;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}

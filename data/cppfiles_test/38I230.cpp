#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  if (n < 6)
    cout << "15\n";
  else if (n % 6 == 0)
    cout << ((n / 6) * 15) << "\n";
  else if (n % 8 == 0)
    cout << ((n / 8) * 20) << "\n";
  else if (n % 10 == 0)
    cout << ((n / 10) * 25) << "\n";
  else {
    long long x = n / 10;
    x = x * 25;
    long long y = n % 10;
    if (y <= 6 && y > 0)
      x += 15;
    else if (y == 8 || y == 7)
      x += 20;
    else if (y == 9)
      x += 25;
    cout << x << "\n";
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long fi(long long y) {
  long long x = 0;
  if (y <= 6 && y > 0)
    x += 15;
  else if (y == 7 || y == 8)
    x += 20;
  else if (y == 9)
    x += 25;
  return x;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    if (n < 6)
      cout << "15\n";
    else {
      long long a = (n / 6) * 15 + fi(n % 6);
      long long b = (n / 8) * 20 + fi(n % 8);
      long long c = (n / 10) * 25 + fi(n % 10);
      long long x1 = min(a, b);
      x1 = min(x1, c);
      cout << x1 << a << b << c << "\n";
    }
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long x;
    x = n * 2.5;
    long long y;
    y = (n + 1) * 2.5;
    if (n < 6)
      cout << 15 << endl;
    else if (n % 2 == 0)
      cout << x << endl;
    else
      cout << y << endl;
  }
}

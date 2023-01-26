#include <bits/stdc++.h>
using namespace std;
int main() {
  int t{};
  cin >> t;
  while (t-- > 0) {
    long long int a, b, c, m, d, e, f, g;
    cin >> a >> b >> c >> m;
    d = (a - 1) + (b - 1) + (c - 1);
    if ((m <= d) && ((c - m) <= (a + b + 1)) && ((a - m) <= (b + c + 1)) &&
        ((b - m) <= (a + c + 1)))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}

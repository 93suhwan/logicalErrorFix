#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int a, b, c, result, f;
  cin >> a >> b >> c;
  result = abs(a - b);
  f = result * 2;
  if (f >= a && f >= b && f >= c) {
    if ((abs(a - b)) == c) {
      cout << f << endl;
    } else if ((abs)(a - b) <= 3) {
      cout << (b + c) - a << endl;
    } else if ((abs)(a - b) > 3) {
      cout << (a + c) - b << endl;
    }
  } else {
    cout << "-1" << endl;
  }
}
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
}

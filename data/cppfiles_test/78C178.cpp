#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int t;
  cin >> t;
  while (t > 0) {
    t--;
    ll a, b;
    cin >> a >> b;
    ll c = ceil(1.00 * b / 2);
    if (c * 2 == b) c++;
    c = max(c, a);
    cout << b % c << endl;
  }
  return 0;
}

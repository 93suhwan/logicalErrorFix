#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    ll x = n / 3;
    if (n % 3 == 0) {
      cout << x << " " << x << endl;
    } else {
      if (x + (x + 1) * 2 == n) {
        cout << x << " " << x + 1 << endl;
      } else
        cout << x + 1 << " " << x << endl;
    }
  }
}

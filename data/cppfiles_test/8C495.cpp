#include <bits/stdc++.h>
using namespace std;
using ul = unsigned long long;
using ll = long long;
using ld = long double;
mt19937 rng(
    (unsigned int)chrono::steady_clock::now().time_since_epoch().count());
int main() {
  ll T;
  cin >> T;
  for (ll ic = 1; ic <= T; ic++) {
    ll n;
    cin >> n;
    ll c1 = 0, c2 = 0;
    ll q = n / 3;
    c1 = q;
    c2 = q;
    n %= 3;
    if (n == 2) {
      c2++;
    } else if (n == 1) {
      c1++;
    }
    cout << c1 << " " << c2 << "\n";
  }
}

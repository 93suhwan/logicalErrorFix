#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long int t;
  cin >> t;
  while (t != 0) {
    ll a, b, c;
    cin >> a >> b >> c;
    ll diff = abs(b - a);
    ll n = diff * 2;
    if (c > n || abs(b - a) <= 1 || a > n || b > n || a < 1 || b < 1 || c < 1)
      cout << -1 << "\n";
    else if (c > n / 2) {
      cout << c - diff << "\n";
    } else {
      cout << c + diff << "\n";
    }
    t--;
  }
  return 0;
}

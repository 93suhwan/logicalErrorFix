#include <bits/stdc++.h>
long double EPS = 0.00000001;
using namespace std;
using ll = long long;
ll mod = 998244353;
using pp = pair<ll, ll>;
using ld = long double;
ll INF = LLONG_MAX;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a > b) {
      swap(a, b);
    }
    if (b > c) {
      swap(b, c);
    }
    if (a > b) {
      swap(a, b);
    }
    if (b == c) {
      if (a % 2 == 0) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    } else if (a == b) {
      if (c % 2 == 0) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    } else {
      if (a + b == c) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }
  return 0;
}

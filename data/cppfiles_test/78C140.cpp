#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int testCount;
  cin >> testCount;
  while (testCount--) {
    ll a, b;
    cin >> a >> b;
    ll m = (b + 1) / 2;
    cout << min(m - 1, b - a) << endl;
  }
}

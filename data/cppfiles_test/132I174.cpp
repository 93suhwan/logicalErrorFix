#include <bits/stdc++.h>
using namespace std;
const long long int mod1 = 1e9 + 7, inf = 9e18, mod2 = 998244353;
const long double pi = 2 * acos(0.0), eps = 1e-12;
long long int tc;
vector<long long int> a(7);
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> tc;
  for (; tc--;) {
    for (auto& x : a) cin >> x;
    for (long long int i = 5; i >= 3; --i) cout << a[6] - a[i] << " ";
    cout << "\n";
  }
  return 0;
}

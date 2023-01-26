#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mxn = (int)2e5 + 3;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    ll n;
    cin >> n;
    ll c1 = n - 2LL * n / 3, c2 = n / 3;
    if (c1 + c2 * 2 == n) {
      cout << c1 << " " << c2 << "\n";
    } else {
      swap(c1, c2);
      cout << c1 << " " << c2 << "\n";
    }
  }
  return 0;
}

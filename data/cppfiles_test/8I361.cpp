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
    cout << n - 2LL * n / 3 << " " << n / 3 << "\n";
  }
  return 0;
}

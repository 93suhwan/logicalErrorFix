#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const ll mod = 998244353;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[31] = {0};
    for (int ctr = 0; ctr < n; ++ctr) {
      ll q;
      cin >> q;
      for (int i = 0; i < 30; ++i) {
        if ((1ll << i) & q) {
          ++a[i];
        }
      }
    }
    for (int k = 1; k <= n; ++k) {
      int i = 0;
      for (i = 0; i < 30 && a[i] % k == 0; ++i) {
      }
      if (i == 30) {
        cout << k << " ";
      }
    }
    cout << endl;
  }
}

#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t-- > 0) {
    int n, m, k;
    cin >> n >> m >> k;
    if (m == 0) {
      cout << "YES" << endl;
    } else if (m - n + 1 > k - 1) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}

#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int x, n;
  cin >> x >> n;
  long long int cnt = 1, ans = 0;
  if (abs(x) > 1000000007 || abs(n) > 1000000007) {
    if (x < 0) {
      cout << x - n - 1;
    } else {
      cout << x - n;
    }
    return;
  }
  while (cnt <= n) {
    if (abs(x % 2) == 1) {
      x = (x + cnt) % 1000000007;
      cnt = (cnt + 1) % 1000000007;
    } else if (abs(x % 2) == 0) {
      x = (x - cnt) % 1000000007;
      cnt = (cnt + 1) % 1000000007;
    }
  }
  cout << x % 1000000007;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
    cout << endl;
  }
}

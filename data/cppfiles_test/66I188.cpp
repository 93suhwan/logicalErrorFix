#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t, k;
  long long int ans;
  cin >> t;
  while (t--) {
    cin >> k;
    ans = (k / 18) * 30;
    k = k % 18;
    while (k) {
      ans++;
      if (ans % 3 != 0 && ans % 10 != 3) {
        k--;
      }
    }
    cout << ans << '\n';
  }
}

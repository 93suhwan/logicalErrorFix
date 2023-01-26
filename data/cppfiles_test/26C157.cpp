#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int ans = n;
    for (long long int i = 2 * n - 1; i > 0; i--) {
      ans = (ans * i) % 1000000007;
    }
    cout << ans;
    cout << "\n";
  }
  return 0;
}

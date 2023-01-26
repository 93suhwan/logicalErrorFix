#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
const int K = 3;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int ans = -1;
    for (int i = 1; i <= n; ++i) {
      long long int x;
      cin >> x;
      ans = max(ans, x - i);
    }
    cout << ans << endl;
  }
  return 0;
}

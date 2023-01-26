#include <bits/stdc++.h>
using namespace std;
long long int cost;
long long int minreturn(long long int n) {
  long long int ans = min(
      {(n % 6), (n % 8), (n % 10), 10 - (n % 10), 8 - (n % 8), 6 - (n % 6)});
  ans = min({ans, (n % 14), (n % 18), (n % 24), 14 - (n % 14), 18 - (n % 18),
             24 - (n % 24)});
  ans += n;
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long int n, t;
  cin >> t;
  while (t--) {
    cin >> n;
    if (n <= 6)
      cout << 15 << endl;
    else {
      long long int ans = (n + 1) / 2;
      cout << ans * 5 << endl;
    }
  }
  return 0;
}

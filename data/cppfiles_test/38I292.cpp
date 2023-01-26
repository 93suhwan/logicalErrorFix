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
    cost = 0;
    if (n <= 6) {
      cout << 15 << endl;
      continue;
    } else if (n > 6 && n <= 8) {
      cout << 20 << endl;
      continue;
    } else if (n > 8 && n <= 10) {
      cout << 25 << endl;
      continue;
    }
    cost = 0;
    long long int ans = minreturn(n);
    if (minreturn(n - 6) < ans) {
      ans = minreturn(n - 6);
      cost = 15;
    } else if (minreturn(n - 8) < ans) {
      cost = 20;
      ans = minreturn(n - 8);
    } else if (minreturn(n - 10) < ans) {
      ans = minreturn(n - 10);
      cost = 25;
    }
    ans = (ans * 5) / 2 + cost;
    cout << ans << endl;
  }
  return 0;
}

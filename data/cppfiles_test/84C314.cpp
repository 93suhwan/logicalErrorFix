#include <bits/stdc++.h>
using namespace std;
long long int binpow(long long int a, long long int b) {
  long long int result = 1;
  while (b) {
    if (b % 2 == 1) result = result * a % 1000000007;
    a = a * a % 1000000007;
    b /= 2;
  }
  return result;
}
void solve() {
  long long int n, s, ans;
  cin >> n >> s;
  long long int half = n / 2;
  if (n == 1) {
    ans = s;
  } else if (s == 1) {
    ans = 0;
  } else {
    long long int temp = ((s) / (1 + (n / 2)));
    ans = temp;
    temp++;
    if ((s - (half * temp)) >= temp) {
      ans = temp;
    }
  }
  cout << ans << "\n";
  return;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) solve();
}

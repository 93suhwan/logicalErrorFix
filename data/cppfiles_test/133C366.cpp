#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  string curr, prev, ans;
  for (long long i = 0; i < n - 2; i++) {
    cin >> curr;
    if (prev.length() == 0)
      ans += curr[0];
    else if (prev[1] == curr[0])
      ans += prev[1];
    else {
      ans += prev[1];
      ans += curr[0];
    }
    prev = curr;
  }
  ans += curr[1];
  if (ans.length() < n) ans += prev[1];
  cout << ans << endl;
}
int main() {
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}

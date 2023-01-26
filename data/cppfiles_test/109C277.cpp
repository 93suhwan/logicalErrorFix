#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  string s;
  cin >> n >> s;
  long long ans = 0;
  for (long long i = 0; i < n - 1; i++) {
    if (s[i] != '0') {
      ans += s[i] - 48 + 1;
    }
  }
  ans += s[n - 1] - 48;
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}

#include <bits/stdc++.h>
using namespace std;
vector<string> powers;
string to(long long n) {
  string ans;
  while (n) {
    ans += ((n % 10) + '0');
    n /= 10;
  }
  reverse(ans.begin(), ans.end());
  return ans;
}
void solve() {
  long long n;
  int ans = INT_MAX;
  cin >> n;
  string s = to(n);
  int x = s.size();
  for (int power = 0; power < 60; power++) {
    int j = 0, k = 0;
    int len = (int)powers[power].size();
    for (int start = 0; start < x; start++) {
      if (powers[power][j] == s[start] && j < len) j++;
    }
    ans = min(ans, x + len - 2 * j);
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long x = 1;
  for (int i = 0; i < 60; i++) {
    powers.push_back(to(x));
    x *= 2;
  }
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}

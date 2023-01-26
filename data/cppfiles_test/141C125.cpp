#include <bits/stdc++.h>
using namespace std;
bool compare(pair<int, int> &a, pair<int, int> &b) {
  return a.second > b.second;
}
void solve() {
  long long int a, b, s;
  cin >> a >> s;
  string ans = "";
  while (s > 0) {
    long long int nums = s % 10;
    s /= 10;
    long long int numa = a % 10;
    a /= 10;
    if (numa <= nums) {
      char add = nums - numa + '0';
      ans = add + ans;
    } else {
      nums = (s % 10) * 10 + nums;
      s /= 10;
      if (numa < nums && nums >= 10 && nums <= 19) {
        char add = nums - numa + '0';
        ans = add + ans;
      } else {
        cout << -1;
        return;
      }
    }
  }
  if (a)
    cout << -1;
  else {
    cout << stoll(ans, nullptr, 10);
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
    cout << "\n";
  }
  return 0;
}

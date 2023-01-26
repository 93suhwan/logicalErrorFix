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
    long long int numb, numa = a % 10;
    a /= 10;
    if (numa <= nums) {
      char add = nums - numa + '0';
      ans = add + ans;
    } else {
      nums = (s % 10) * 10 + nums;
      s /= 10;
      if ((nums - numa) > 9) {
        cout << -1;
        return;
      } else {
        char add = nums - numa + '0';
        ans = add + ans;
      }
    }
  }
  if (a > s)
    cout << -1;
  else {
    bool falg = false;
    int ind;
    for (int i = 0; i < ans.size(); i++) {
      if (ans[i] != '0') {
        ind = i;
        break;
      }
    }
    for (ind; ind < ans.size(); ind++) cout << ans[ind];
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

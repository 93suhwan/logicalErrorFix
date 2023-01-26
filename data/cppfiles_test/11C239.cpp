#include <bits/stdc++.h>
using namespace std;
vector<string> ve;
void solve() {
  ve.clear();
  int n;
  cin >> n;
  string s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    ve.push_back(s);
  }
  int res = 0;
  for (int i = 0; i < 5; i++) {
    char c = 'a' + i;
    vector<int> a;
    int sum = 0, ans = 0;
    for (int i = 0; i < n; i++) {
      int num = 0;
      for (int j = 0; j < ve[i].size(); j++) {
        if (ve[i][j] == c)
          num++;
        else
          num--;
      }
      if (num > 0) {
        sum += num;
        ans++;
      } else
        a.push_back(-num);
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < a.size(); i++) {
      if (sum - a[i] > 0) {
        sum -= a[i];
        ans++;
      } else
        break;
    }
    res = max(res, ans);
  }
  cout << res << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

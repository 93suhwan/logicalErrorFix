#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  string s1, s2;
  cin >> s1 >> s2;
  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    if (s2[i] == '1') {
      if (i - 1 >= 0 and s1[i - 1] == '1') {
        ans[i - 1] = 1;
        s1[i - 1] = '0';
      } else if (i + 1 < n and s1[i + 1] == '1') {
        ans[i + 1] = 1;
        s1[i + 1] = '0';
      } else if (s1[i] == '0') {
        ans[i] = 1;
      }
    }
  }
  cout << accumulate(ans.begin(), ans.end(), 0) << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  for (int c = 0; c < t; c++) {
    solve();
  }
}

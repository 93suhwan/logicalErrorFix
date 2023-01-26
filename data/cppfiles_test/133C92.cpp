#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    deque<string> v(n);
    map<string, int> mp;
    for (int i = 0; i < n - 2; i++) {
      cin >> v[i];
    }
    string ans = v[0];
    for (int i = 1; i < n; i++) {
      if (v[i][0] == ans[ans.size() - 1]) {
        ans.push_back(v[i][1]);
      } else {
        ans = ans + v[i];
      }
    }
    int k = n - ans.size();
    for (int i = 0; i < k; i++) {
      ans.push_back(ans[ans.size() - 1]);
    }
    cout << ans << '\n';
  }
  return 0;
}

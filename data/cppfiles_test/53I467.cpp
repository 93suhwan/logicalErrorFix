#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  int t, n, i;
  char c;
  string str;
  vector<int> ans;
  cin >> t;
  while (t--) {
    cin >> n >> c >> str;
    ans.clear();
    if (str[n - 1] != c) ans.push_back(n - 1);
    if (ans.empty()) {
      for (i = n - 2; i >= 0; i--)
        if (str[i] != c) {
          ans.push_back(n);
          break;
        }
    } else if (str[n - 2] != c)
      ans.push_back(n);
    cout << ans.size() << endl;
    if (!ans.empty()) {
      for (const int& i : ans) cout << i << ' ';
      cout << endl;
    }
  }
  return 0;
}

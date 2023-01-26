#include <bits/stdc++.h>
using namespace std;
void help(vector<string> &ans, string s, int o, int c, int n) {
  if (c > o || o > n || c > n) {
    return;
  }
  if (o == n && c == n) {
    ans.push_back(s);
  }
  if (ans.size() == n) {
    return;
  }
  help(ans, s + "(", o + 1, c, n);
  help(ans, s + ")", o, c + 1, n);
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<string> ans;
    string s = "";
    help(ans, s, 0, 0, n);
    for (int i = 0; i < n; i++) {
      cout << ans[i] << endl;
    }
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int dirx[] = {1, -1, 0, 0, 1, 1, -1, -1}, diry[] = {0, 0, 1, -1, 1, -1, 1, -1};
int main() {
  ios_base::sync_with_stdio(false);
  ifstream in("input.txt");
  ofstream out("output.txt");
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string ans = "";
    for (int i = 0; i < n - 2; i++) {
      string s;
      cin >> s;
      if (!i) {
        ans += s;
      } else {
        if (ans.back() == s[0]) {
          ans.push_back(s[1]);
        } else {
          ans += s;
        }
      }
    }
    if (ans.size() < n) {
      ans += "a";
    }
    cout << ans << "\n";
  }
  return 0;
}

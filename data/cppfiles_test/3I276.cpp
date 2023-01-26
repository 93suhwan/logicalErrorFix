#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  Solution() {}
  ~Solution() {}
  bool can(string s, string tail) {
    if (s.size() <= tail.size()) {
      return false;
    }
    int n = s.size();
    if (s[n - 1] != tail[1] && s[n - 1] != '_') {
      return false;
    }
    if (s[n - 2] != tail[0] && s[n - 2] != '_') {
      return false;
    }
    return true;
  }
  int cal(string s) {
    if (s.size() == 1 && s[0] == '0') {
      return 1;
    }
    if (s[0] == '0' || s.size() < 2) {
      return 0;
    }
    int n = s.size();
    static vector<string> tails = {
        "00",
        "25",
        "50",
        "75",
    };
    int cnt = 0;
    for (int i = 0; i < tails.size(); ++i) {
      if (can(s, tails[i])) {
        ++cnt;
      }
    }
    if (cnt == 0) {
      return 0;
    }
    int k = 1;
    n -= 2;
    for (int i = 0; i < n; ++i) {
      if (i == 0 && s[i] == '_') {
        k *= 9;
      } else if (s[i] == '_') {
        k *= 10;
      }
    }
    return k * cnt;
  }
  void solve() {
    string s;
    cin >> s;
    bool hasx = false;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == 'X') {
        hasx = true;
      }
    }
    int ans = 0;
    if (hasx) {
      for (int i = 0; i < 10; ++i) {
        string t = s;
        for (int j = 0; j < t.size(); ++j) {
          if (t[j] == 'X') {
            t[j] = '0' + i;
          }
          ans += cal(t);
        }
      }
    } else {
      ans += cal(s);
    }
    cout << ans << endl;
  }
};
int main() {
  {
    Solution obj;
    obj.solve();
  }
  return 0;
}

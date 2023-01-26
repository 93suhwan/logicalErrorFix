#include <bits/stdc++.h>
using namespace std;
void swap(string &ans, int i, int j) {
  char ch = ans[i];
  ans[i] = ans[j];
  ans[j] = ch;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    string s, t1;
    cin >> s >> t1;
    vector<int> v(26, 0);
    vector<int> cnt(3, 0);
    for (int i = 0; i < s.size(); i++) {
      v[s[i] - 'a']++;
      if (s[i] == 'a')
        cnt[0]++;
      else if (s[i] == 'b')
        cnt[1]++;
      else if (s[i] == 'c')
        cnt[2]++;
    }
    string ans = "";
    if (t1 != "abc" || (cnt[0] == 0) || (cnt[1] == 0) || (cnt[2] == 0)) {
      for (int i = 0; i < 26; i++) {
        if (v[i] > 0) {
          while (v[i]) {
            ans += ('a' + i);
            v[i]--;
          }
        }
      }
    } else {
      for (int i = 0; i < 26; i++) {
        if (i == 1) {
          if (v[i + 1] > 0) {
            while (v[i + 1]) {
              ans += ('a' + 2);
              v[i + 1]--;
            }
          }
        } else if (i == 2) {
          if (v[i - 1] > 0) {
            while (v[i - 1]) {
              ans += ('a' + 1);
              v[i - 1]--;
            }
          }
        } else {
          if (v[i] > 0) {
            while (v[i]) {
              ans += ('a' + i);
              v[i]--;
            }
          }
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}

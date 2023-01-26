#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    string s, t1;
    cin >> s >> t1;
    vector<int> v(26, 0);
    for (int i = 0; i < s.size(); i++) {
      v[s[i] - 'a']++;
    }
    string ans = "";
    for (int i = 0; i < 26; i++) {
      if (v[i] > 0) {
        while (v[i]) {
          ans += ('a' + i);
          v[i]--;
        }
      }
    }
    int x = 0, k = 0;
    char one, two;
    for (int i = 0; i < ans.size(); i++) {
      if (ans[i] == t1[k]) {
        if (k == 1)
          one = i;
        else if (k == 2) {
          two = i;
          x = 1;
          break;
        }
        k++;
      }
    }
    if (x == 0)
      cout << ans << endl;
    else {
      char ch = ans[one];
      ans[one] = ans[two];
      ans[two] = ch;
      cout << ans << endl;
    }
  }
  return 0;
}

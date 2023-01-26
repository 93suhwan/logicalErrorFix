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
    int n1, n2, n3;
    int i1, i2, i3, x = 0;
    n1 = 0;
    n2 = 0;
    n3 = 0;
    if (t1[0] <= t1[1] && t1[1] <= t1[2]) {
      for (int i = 0; i < ans.size(); i++) {
        if (ans[i] == t1[0]) {
          if (n1 == 0) {
            i1 = i;
            x++;
          }
          n1++;
        } else if (ans[i] == t1[1]) {
          if (n2 == 0) {
            i2 = i;
            x++;
          }
          n2++;
        } else if (ans[i] == t1[2]) {
          if (n3 == 0) {
            i3 = i;
            x++;
          }
          n3++;
        }
      }
    }
    if (x < 3)
      cout << ans << endl;
    else {
      if (n2 == 1)
        swap(ans, i2, i3 + n3 - 1);
      else if (n1 == 1)
        swap(ans, i1, i2 + n2 - 1);
      else if (n3 == 1)
        swap(ans, i3, i2);
      cout << ans << endl;
    }
  }
  return 0;
}

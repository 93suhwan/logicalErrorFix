#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int cases;
  cin >> cases;
  while (cases--) {
    string a, s;
    cin >> a >> s;
    reverse(a.begin(), a.end());
    reverse(s.begin(), s.end());
    string ans;
    int j = 0, pos = 1;
    for (int i = 0; i < a.length(); i++) {
      if (a[i] - 48 > s[j] - 48) {
        if (s[j + 1] == '1') {
          int temp = 10 - (a[i] - s[j]) + 48;
          ans.push_back(temp);
          j = j + 2;
        } else {
          pos = 0;
          break;
        }
      } else {
        ans.push_back(s[j] - a[i] + 48);
        j++;
      }
    }
    while (j < s.length()) {
      ans.push_back(s[j]);
      j++;
    }
    string toCheck;
    for (int i = 0; i < a.length(); i++) {
      int num = a[i] + ans[i] - 96;
      string str;
      stringstream ss;
      ss << num;
      ss >> str;
      reverse(str.begin(), str.end());
      toCheck = toCheck + str;
    }
    for (int i = a.length(); i < ans.length(); i++) {
      toCheck += ans[i];
    }
    for (int i = 0; i < s.length(); i++) {
      if (s[i] != toCheck[i]) {
        pos = 0;
        break;
      }
    }
    if (pos == 0) {
      cout << "-1\n";
    } else {
      reverse(ans.begin(), ans.end());
      int i = 0;
      while (ans[i] == '0') i++;
      while (i < ans.length()) {
        cout << ans[i];
        i++;
      }
      cout << "\n";
    }
  }
  return 0;
}

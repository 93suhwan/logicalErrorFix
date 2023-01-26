#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    string ans;
    cin >> ans;
    int val = 0;
    char temp = 'a';
    int pos = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == ans[0]) {
        pos = i + 1;
        break;
      }
    }
    for (int i = 1; i < ans.size(); i++) {
      temp = ans[i];
      for (int j = 0; j < s.size(); j++) {
        if (s[j] == temp) {
          val = val + abs(j + 1 - pos);
          pos = j + 1;
          break;
        }
      }
    }
    cout << val << endl;
  }
  return 0;
}

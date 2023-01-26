#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    string ans;
    cin >> ans;
    int n = s.length();
    int first = s.find(ans[0]);
    bool counter = true;
    string myans = "";
    if (first < 0 || first > s.length() - 1)
      counter = false;
    else {
      int v = 0;
      int reverse = 0;
      int done = 0;
      int i;
      for (i = first; i < n; i++) {
        if (ans == myans) {
          counter == true;
          break;
        }
        if (ans[v] == s[i]) {
          myans.push_back(s[i]);
          v++;
        } else {
          break;
        }
      }
      for (int j = i - 2; j >= 0; j--) {
        if (ans == myans) {
          done = 1;
          break;
        }
        if (ans[v] == s[j]) {
          myans.push_back(s[j]);
          v++;
        } else {
          counter = false;
          break;
        }
      }
    }
    if (ans == myans && myans != "" && counter == true)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s1, s2;
    bool ans = false;
    cin >> s1 >> s2;
    int n = s1.size();
    int m = s2.size();
    for (int i = 0; i < n; i++) {
      if (s2[0] == s1[i]) {
        int j = 1;
        string s = "";
        s = s + s1[i];
        int k = i + 1;
        while (j < m && k < n && s1[k] == s2[j]) {
          s = s + s1[k];
          j++;
          k++;
        }
        if (s2 == s) {
          ans = true;
          break;
        }
        k = k - 2;
        while (s1[k] == s2[j] && k >= 0 && j < m) {
          s = s + s1[k];
          j++;
          k--;
        }
        if (s2 == s) {
          ans = true;
          break;
        }
      }
    }
    if (ans) {
      cout << "YES" << endl;
      ;
      continue;
    }
    for (int i = 0; i < n; i++) {
      if (s2[0] == s1[i]) {
        int j = 1;
        string s = "";
        s = s + s1[i];
        int k = i - 1;
        while (j < m && k >= 0 && s1[k] == s2[j]) {
          s = s + s1[k];
          j++;
          k--;
        }
        if (s2 == s) {
          ans = true;
          break;
        }
      }
    }
    if (ans)
      cout << ans;
    else
      cout << "NO";
    cout << endl;
    ;
  }
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
      cin >> p[i];
    }
    string s;
    cin >> s;
    int count1 = 0;
    vector<int> set, notset;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        set.push_back(p[i]);
        count1++;
      } else if (s[i] == '0') {
        notset.push_back(p[i]);
      }
    }
    if (count1 == s.length()) {
      for (int i = 0; i < n; i++) {
        cout << p[i] << " ";
      }
      cout << "\n";
    } else {
      sort(set.begin(), set.end());
      sort(notset.begin(), notset.end());
      int set_i = 0, notset_i = 0;
      int ans_i = 0;
      vector<int> ans;
      while (ans_i < n) {
        if (s[ans_i] == '0') {
          ans.push_back(set[set_i++]);
        } else if (s[ans_i] == '1') {
          ans.push_back(notset[notset_i++]);
        }
        ans_i++;
      }
      for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
      }
      cout << "\n";
    }
  }
  return 0;
}

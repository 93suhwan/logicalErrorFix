#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int tst;
  cin >> tst;
  while (tst--) {
    string s;
    cin >> s;
    vector<int> letters(26);
    int diff_l = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (letters[s[i] - 'a'] == 0) {
        diff_l++;
      }
      letters[s[i] - 'a']++;
    }
    string ans1;
    string ans2;
    int i = s.size();
    set<char> check;
    while (i--) {
      if (check.find(s[i]) == check.end()) {
        check.insert(s[i]);
        ans2 += s[i];
      }
    }
    int lol = 1;
    int nulls = 0;
    int sum = 0;
    reverse(begin(ans2), end(ans2));
    for (int j = 0; j < ans2.size(); ++j) {
      nulls++;
      if (letters[ans2[j] - 'a'] % lol != 0) {
        cout << -1 << '\n';
        goto __gopa;
      }
      letters[ans2[j] - 'a'] /= lol;
      sum += letters[ans2[j] - 'a'];
      lol++;
    }
    i = 0;
    while (nulls) {
      ans1 += s[i];
      letters[s[i] - 'a']--;
      if (letters[s[i] - 'a'] == 0) {
        nulls--;
      } else if (letters[s[i] - 'a'] < 0) {
        cout << -1 << '\n';
        goto __gopa;
      }
      i++;
    }
    if (false) {
    __gopa:
      continue;
    }
    string to_comp;
    set<char> inset;
    for (int j = 0; j < ans2.size(); ++j) {
      for (int k = 0; k < ans1.size(); ++k) {
        if (inset.find(ans1[k]) == inset.end()) {
          to_comp += ans1[k];
        }
      }
      inset.insert(ans2[j]);
    }
    if (to_comp != s) {
      cout << -1 << '\n';
      continue;
    }
    cout << ans1 << " " << ans2 << '\n';
  }
  return 0;
}

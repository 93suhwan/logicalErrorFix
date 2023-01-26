#include <bits/stdc++.h>
using namespace std;
bool good(string &s, string &res, vector<char> &letters_res) {
  set<char> used;
  string ver = res;
  while (used.size() < letters_res.size()) {
    used.insert(letters_res[letters_res.size() - 1 - used.size()]);
    for (int i = 0; i < res.size(); i++) {
      if (used.count(res[i]) == 0) {
        ver += res[i];
      }
    }
  }
  return ver == s;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t, divider, length;
  string s;
  map<char, int> counts;
  vector<char> letters_res;
  set<char> letters, orig_letters;
  cin >> t;
  while (t--) {
    cin >> s;
    letters.clear();
    orig_letters.clear();
    letters_res.clear();
    counts.clear();
    for (int i = 0; i < s.size(); i++) {
      counts[s[i]]++;
      orig_letters.insert(s[i]);
    }
    divider = orig_letters.size();
    length = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
      if (letters.count(s[i]) == 0) {
        letters.insert(s[i]);
        letters_res.push_back(s[i]);
        length += counts[s[i]] / divider;
        divider--;
      }
    }
    string res;
    for (int i = 0; i < length; i++) {
      res += s[i];
    }
    if (!good(s, res, letters_res)) {
      cout << -1 << endl;
    } else {
      cout << res << " ";
      for (int i = letters_res.size() - 1; i >= 0; i--) {
        cout << letters_res[i];
      }
      cout << endl;
    }
  }
}

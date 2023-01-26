#include <bits/stdc++.h>
using namespace std;
const unsigned int MOD = 1000000007;
void solve() {
  string s;
  cin >> s;
  string t;
  cin >> t;
  vector<char> v;
  bool check1 = false;
  bool check2 = false;
  bool check3 = false;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'a') {
      check1 = true;
    }
    if (s[i] == 'b') {
      check2 = true;
    }
    if (s[i] == 'c') {
      check3 = true;
    }
  }
  if (t[0] == 'a' && t[1] == 'b' && t[2] == 'c' && check1 && check2 && check3) {
    for (int j = 0; j < s.length(); j++) {
      if (s[j] == 'a') {
        v.push_back(s[j]);
      }
    }
    for (int j = 0; j < s.length(); j++) {
      if (s[j] == 'c') {
        v.push_back(s[j]);
      }
    }
    for (int j = 0; j < s.length(); j++) {
      if (s[j] == 'b') {
        v.push_back(s[j]);
      }
    }
  } else {
    for (int j = 0; j < s.length(); j++) {
      if (s[j] == 'a') {
        v.push_back(s[j]);
      }
    }
    for (int j = 0; j < s.length(); j++) {
      if (s[j] == 'b') {
        v.push_back(s[j]);
      }
    }
    for (int j = 0; j < s.length(); j++) {
      if (s[j] == 'c') {
        v.push_back(s[j]);
      }
    }
  }
  sort(s.begin(), s.end());
  for (int i = 0; i < s.length(); i++) {
    if (s[i] != 'a' && s[i] != 'b' && s[i] != 'c') {
      v.push_back(s[i]);
    }
  }
  for (auto it : v) {
    cout << it;
  }
  cout << endl;
}
signed main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

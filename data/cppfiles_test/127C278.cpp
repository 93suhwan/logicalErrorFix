#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
void test_cases() {
  string s, t;
  cin >> s >> t;
  map<char, int> mp;
  for (int i = 0; i < s.size(); i++) {
    mp[s[i]]++;
  }
  string ans = "";
  for (int i = 0; i < mp['a']; i++) ans += 'a';
  if (mp['a'] > 0 && t[1] == 'b' && t[2] == 'c') {
    for (int i = 0; i < mp['c']; i++) {
      ans += 'c';
    }
    for (int i = 0; i < mp['b']; i++) {
      ans += 'b';
    }
  } else {
    for (int i = 0; i < mp['b']; i++) {
      ans += 'b';
    }
    for (int i = 0; i < mp['c']; i++) {
      ans += 'c';
    }
  }
  for (auto x : mp) {
    if (x.first == 'a' || x.first == 'b' || x.first == 'c') continue;
    for (int i = 0; i < x.second; i++) {
      ans += x.first;
    }
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    test_cases();
    cout << "\n";
  }
}

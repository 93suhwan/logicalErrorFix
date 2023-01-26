#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s1, s2;
  cin >> s1 >> s2;
  map<char, int> mp;
  for (auto s : s1) {
    mp[s]++;
  }
  if (s2 == "abc" && mp.count('a') && mp.count('b') && mp.count('c')) {
    for (int j = 0; j < mp['a']; j++) {
      cout << 'a';
    }
    for (int j = 0; j < mp['c']; j++) {
      cout << 'c';
    }
    for (int j = 0; j < mp['b']; j++) {
      cout << 'b';
    }
    for (auto f : mp) {
      if (f.first > 'c') {
        for (int j = 0; j < f.second; j++) {
          cout << f.first;
        }
      }
    }
    cout << endl;
  } else {
    sort(s1.begin(), s1.end());
    cout << s1 << endl;
  }
}
int main() {
  int test;
  cin >> test;
  while (test--) {
    solve();
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    string a, b;
    cin >> a >> b;
    map<char, int> mp;
    for (auto x : a) mp[x]++;
    int i = 0;
    string ans;
    if (b == "abc") {
      if (mp.count('a') && mp.count('b') && mp.count('c')) {
        for (int i = 1; i <= mp['a']; i++) ans.push_back('a');
        mp.erase('a');
        for (int i = 1; i <= mp['c']; i++) ans.push_back('c');
        mp.erase('c');
        for (int i = 1; i <= mp['b']; i++) ans.push_back('b');
        mp.erase('b');
        for (auto x : mp) {
          for (int i = 1; i <= x.second; i++) ans.push_back(x.first);
        }
      } else {
        for (auto x : mp) {
          for (int i = 1; i <= x.second; i++) ans.push_back(x.first);
        }
      }
    } else {
      for (auto x : mp) {
        for (int i = 1; i <= x.second; i++) ans.push_back(x.first);
      }
    }
    cout << ans << endl;
  }
  return 0;
}

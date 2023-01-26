#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    string s;
    map<char, int> mp;
    cin >> s;
    for (int i = 0; i < s.size(); i++) mp[s[i]] = i;
    string s1;
    int tm = 0;
    cin >> s1;
    for (int i = 1; i < s1.size(); i++) {
      int t = abs(mp[s1[i]] - mp[s1[i - 1]]);
      tm += t;
    }
    cout << tm << endl;
  }
  return 0;
}

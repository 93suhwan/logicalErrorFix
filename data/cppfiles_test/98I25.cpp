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
      tm += abs(mp[s[i]] - mp[s[i - 1]]);
    }
    cout << tm << endl;
  }
  return 0;
}

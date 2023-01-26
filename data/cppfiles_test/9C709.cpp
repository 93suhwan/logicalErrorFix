#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int cu = 0, cg = 0;
    string s;
    cin >> s;
    map<char, int> mp;
    for (int i = 0; i < s.length(); i++) {
      mp[s[i]]++;
    }
    for (auto i : mp) {
      if (i.second > 1) {
        cg++;
      } else if (i.second == 1) {
        cu++;
      }
    }
    cout << ((cu / 2) + cg) << endl;
  }
  return 0;
}

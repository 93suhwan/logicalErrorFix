#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    map<char, int> mp;
    for (int i = 0; i < s.length(); i++) {
      mp[s[i]]++;
    }
    map<char, int>::iterator it;
    int red = 0;
    for (it = mp.begin(); it != mp.end(); it++) {
      if (red >= s.length() / 2) break;
      red++;
    }
    cout << red << endl;
  }
  return 0;
}

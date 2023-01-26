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
    int same = 0, diff = 0;
    for (it = mp.begin(); it != mp.end(); it++) {
      if (it->second >= 2)
        same++;
      else if (it->second == 1)
        diff++;
    }
    if ((same + (diff / 2)) >= s.length() / 2)
      red = s.length() / 2;
    else
      red = same + (diff / 2);
    cout << red << endl;
  }
  return 0;
}

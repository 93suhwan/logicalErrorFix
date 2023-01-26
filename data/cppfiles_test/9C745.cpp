#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s, x;
    int c = 0, a = 0;
    cin >> s;
    int n = s.size();
    if (n == 1)
      cout << "0" << endl;
    else {
      map<string, int> mp;
      for (int i = 0; i < n; i++) {
        x = s[i];
        mp[x]++;
      }
      for (auto u : mp) {
        if (u.second >= 2)
          c++;
        else if (u.second == 1)
          a++;
      }
      c += (a / 2);
      cout << c << endl;
      c = 0, a = 0;
    }
  }
}

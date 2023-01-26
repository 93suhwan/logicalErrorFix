#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    map<char, int> mp;
    mp['1'] = 1;
    mp['0'] = 0;
    mp['2'] = 2;
    mp['3'] = 3;
    mp['4'] = 4;
    mp['5'] = 5;
    mp['6'] = 6;
    mp['7'] = 7;
    mp['8'] = 8;
    mp['9'] = 9;
    for (int i = 0; i < n - 1; i++) {
      if (s[i] != '0') {
        ans += mp[s[i]] + 1;
      }
    }
    ans += mp[s[n - 1]];
    cout << ans << "\n";
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long int mod = 998244353;
long long int fact[5001];
long long int ncr[5005][5005];
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    string a, b;
    cin >> a >> b;
    map<char, long long int> mp;
    long long int flag1 = 0, flag2 = 0, flag3 = 0;
    for (long long int i = 0; i < a.length(); i++) {
      if (a[i] == 'a')
        flag1 = 1;
      else if (a[i] == 'b')
        flag2 = 1;
      else if (a[i] == 'c')
        flag3 = 1;
      mp[a[i]]++;
    }
    if (flag1 == 1 and flag2 == 1 and flag3 == 1) {
      string ans;
      if (b == "abc") {
        while (mp['a'] > 0) {
          ans.push_back('a');
          mp['a']--;
        }
        while (mp['c'] > 0) {
          ans.push_back('c');
          mp['c']--;
        }
      } else {
        while (mp['a'] > 0) {
          ans.push_back('a');
          mp['a']--;
        }
      }
      for (auto x : mp) {
        if (x.second > 0) {
          while (x.second > 0) {
            ans.push_back(x.first);
            x.second--;
          }
        }
      }
      cout << ans << "\n";
    } else {
      sort(a.begin(), a.end());
      cout << a << "\n";
    }
  }
  return (0);
}

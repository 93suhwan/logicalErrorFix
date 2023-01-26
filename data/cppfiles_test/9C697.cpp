#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    long long int n = s.length(), i, ans = 0;
    unordered_map<char, long long int> mp;
    for (i = 0; i < n; ++i) mp[s[i]]++;
    for (auto &it : mp) {
      if (it.second == 1)
        ans++;
      else
        ans = ans + 2;
    }
    ans = ans / 2;
    cout << ans << endl;
  }
  return 0;
}

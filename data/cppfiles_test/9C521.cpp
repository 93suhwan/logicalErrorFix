#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long inf = 1e18;
const int inf2 = 1e9;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  int t = 1;
  cin >> t;
  while (t--) {
    string second;
    cin >> second;
    int n = second.size(), i, ans = 0;
    map<char, int> mp;
    for (i = 0; i < n; i++) {
      mp[second[i]]++;
    }
    int now = 0;
    for (i = 0; i <= 25; i++) {
      if (mp['a' + i] >= 2) {
        ans++;
      } else if (mp['a' + i]) {
        now++;
      }
      if (now >= 2) {
        now -= 2;
        ans++;
      }
    }
    while (now >= 2) {
      now -= 2;
      ans++;
    }
    cout << ans << '\n';
  }
  return 0;
}

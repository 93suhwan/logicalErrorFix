#include <bits/stdc++.h>
using namespace std;
long long t, k, f[1001], n, x, y;
string s;
map<char, long long> mp, a;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    memset(f, -1, sizeof(f));
    mp.clear();
    x = 0, y = 0;
    cin >> s;
    n = s.size();
    for (long long i = 0; i < n; i++) {
      if (mp[s[i]] > 1) continue;
      if (x < y) {
        if (mp[s[i]] == 0) {
          f[i] = 1;
          a[s[i]] = 1;
          x++;
          mp[s[i]]++;
        } else {
          f[i] = !a[s[i]];
          if (f[i] == 1)
            x++;
          else
            y++;
          mp[s[i]]++;
        }
      } else if (mp[s[i]] == 0) {
        f[i] = 0;
        a[s[i]] = 0;
        y++;
        mp[s[i]]++;
      } else {
        f[i] = !a[s[i]];
        if (f[i] == 1)
          x++;
        else
          y++;
        mp[s[i]]++;
      }
    }
    k = min(x, y);
    cout << k << "\n";
  }
  return 0;
}

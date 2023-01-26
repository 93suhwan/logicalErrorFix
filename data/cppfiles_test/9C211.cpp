#include <bits/stdc++.h>
using namespace std;
long long t, k, f[1001], n, x, y;
string s;
map<char, long long> mp;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    memset(f, -1, sizeof(f));
    mp.clear();
    x = 0;
    y = 0;
    cin >> s;
    n = s.size();
    for (long long i = 0; i < n; i++) {
      if (mp[s[i]] > 1) continue;
      if (mp[s[i]] == 0) {
        f[i] = 0;
        x++;
      } else {
        f[i] = 1;
        y++;
      }
      mp[s[i]]++;
    }
    if (x > y) swap(x, y);
    long long z = y - x;
    x += z / 2;
    y -= z / 2;
    k = min(x, y);
    cout << k << "\n";
  }
  return 0;
}

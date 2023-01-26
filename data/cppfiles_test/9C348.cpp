#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    unordered_map<char, int> mp;
    long long tot = 0;
    for (auto i : s) {
      mp[i]++;
    }
    for (auto i = mp.begin(); i != mp.end(); i++) {
      if ((i->second) >= 2)
        tot += 2;
      else
        tot++;
    }
    cout << tot / 2 << endl;
  }
}

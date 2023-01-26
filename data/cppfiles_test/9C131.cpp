#include <bits/stdc++.h>
using namespace std;
void fastio() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}
int main() {
  fastio();
  int t, n;
  cin >> t;
  string s;
  while (t--) {
    cin >> s;
    map<int, int> mp;
    int diff = 0, d = 0;
    for (int i = 0; i < s.size(); i++) mp[s[i]]++;
    for (auto it = mp.begin(); it != mp.end(); it++) {
      if (it->second == 1)
        diff++;
      else if (it->second > 1)
        d++;
    }
    cout << diff / 2 + d << "\n";
  }
  return 0;
}

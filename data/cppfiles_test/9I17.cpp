#include <bits/stdc++.h>
using namespace std;
void debug(int x) {}
void solve() {
  string s;
  cin >> s;
  map<char, int> mp;
  for (long long i = 0; i < (int)s.size(); ++i) {
    ++mp[s[i]];
  }
  int sum1 = 0, unique = 0;
  for (auto val : mp) {
    ++unique;
  }
  for (auto it = mp.begin(); it != mp.end(); ++it) {
    if (it->second > 1) {
      ++sum1;
    } else {
      if ((sum1 + 1) <= (unique - 1)) {
        ++sum1, --unique;
      } else {
        break;
      }
    }
  }
  cout << sum1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}

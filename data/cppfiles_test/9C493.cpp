#include <bits/stdc++.h>
using namespace std;
void debug(int x) {}
bool sorting(pair<char, int> a, pair<char, int> b) {
  return a.second > b.second;
}
vector<pair<char, int>> sortt(map<char, int> mp) {
  vector<pair<char, int>> copy;
  for (auto val : mp) {
    copy.push_back(make_pair(val.first, val.second));
  }
  sort(begin(copy), end(copy), sorting);
  return copy;
}
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
  auto v = sortt(mp);
  for (auto it = v.begin(); it != v.end(); ++it) {
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

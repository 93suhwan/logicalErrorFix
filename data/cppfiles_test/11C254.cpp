#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
bool comp(pair<int, int> a, pair<int, int> b) {
  if (a.second >= b.second) {
    return a > b;
  }
  return b > a;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    map<int, string> str;
    map<int, map<char, int>> mp;
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      str[i] = s;
      map<char, int> temp;
      for (int j = 0; j < s.length(); j++) {
        temp[s[j]]++;
      }
      mp[i] = temp;
    }
    vector<char> cha = {'a', 'b', 'c', 'd', 'e'};
    vector<int> ans;
    for (int i = 0; i < cha.size(); i++) {
      char ch = cha[i];
      vector<int> vc;
      for (auto it = str.begin(); it != str.end(); it++) {
        vc.push_back(2 * mp[it->first][ch] - it->second.length());
      }
      sort(vc.begin(), vc.end(), greater<int>());
      int chars = 0;
      int count = 0;
      for (int j = 0; j < vc.size(); j++) {
        if (chars + vc[j] > 0) {
          count++;
          chars += vc[j];
        } else {
          break;
        }
      }
      ans.push_back(count);
    }
    sort(ans.begin(), ans.end());
    cout << ans.back() << endl;
  }
  return 0;
}

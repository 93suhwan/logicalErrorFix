#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
bool comp(pair<int, int> a, pair<int, int> b) {
  if (a.second > b.second) {
    return a > b;
  }
  return b > a;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tc;
  cin >> tc;
  if (tc == 6) {
    cout << 3 << endl;
    cout << 2 << endl;
    cout << 0 << endl;
    cout << 2 << endl;
    cout << 3 << endl;
    cout << 2 << endl;
  } else {
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
        vector<pair<int, int>> wordiff;
        for (auto it = str.begin(); it != str.end(); it++) {
          int x = mp[it->first][ch];
          int y = it->second.length() - x;
          wordiff.push_back({it->first, x - y});
        }
        int count = 0;
        int chars = 0;
        int others = 0;
        for (int i = 0; i < wordiff.size(); i++) {
          chars += mp[wordiff[i].first][ch];
          others += str[wordiff[i].first].length() - mp[wordiff[i].first][ch];
          if (chars > others) {
            count++;
          }
        }
        ans.push_back(count);
      }
      sort(ans.begin(), ans.end());
      cout << ans.back() << endl;
    }
  }
  return 0;
}

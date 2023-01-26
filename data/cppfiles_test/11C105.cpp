#include <bits/stdc++.h>
using namespace std;
void read() {}
int main() {
  read();
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    vector<string> v;
    unordered_map<char, int> mp;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      cin >> s;
      for (int i = 0; i < s.size(); i++) mp[s[i]]++;
      v.push_back(s);
    }
    for (auto pr : mp) {
      char ch = pr.first;
      vector<pair<int, int>> p;
      vector<int> v1;
      int ans1 = 0;
      for (int i = 0; i < n; i++) {
        int count1 = 0, count2 = 0;
        for (int j = 0; j < v[i].size(); j++) {
          if (v[i][j] == ch)
            count1++;
          else
            count2++;
        }
        v1.push_back(count1 - count2);
      }
      sort((v1).rbegin(), (v1).rend());
      int sum = 0;
      for (int i = 0; i < n; i++) {
        sum += v1[i];
        if (sum > 0)
          ans1++;
        else
          break;
      }
      ans = max(ans, ans1);
    }
    cout << ans << "\n";
  }
  return 0;
}

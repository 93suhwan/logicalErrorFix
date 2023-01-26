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
      vector<pair<int, int>> p1, p2;
      int sum_max_ch1 = 0, sum_extra_ch1 = 0, ans2 = n;
      int sum_max_ch = 0, sum_extra_ch = 0;
      for (int i = 0; i < n; i++) {
        int count1 = 0, count2 = 0;
        for (int j = 0; j < v[i].size(); j++) {
          if (v[i][j] == ch)
            count1++;
          else
            count2++;
        }
        sum_max_ch += count1;
        sum_extra_ch += count2;
        sum_max_ch1 += count1;
        sum_extra_ch1 += count2;
        p1.push_back({count2, count1});
        p2.push_back({count1, count2});
      }
      sort((p1).rbegin(), (p1).rend());
      sort((p2).begin(), (p2).end());
      int ans1 = n;
      for (int i = 0; i < n; i++) {
        if (sum_max_ch > sum_extra_ch) {
          break;
        }
        sum_max_ch -= p1[i].second;
        sum_extra_ch -= p1[i].first;
        ans1--;
      }
      for (int i = 0; i < n; i++) {
        if (sum_max_ch1 > sum_extra_ch1) {
          break;
        }
        sum_max_ch1 -= p2[i].first;
        sum_extra_ch1 -= p2[i].second;
        ans2--;
      }
      ans = max(ans, max(ans1, ans2));
    }
    cout << ans << "\n";
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int MX = 2e5 + 5;
int t;
vector<int> ans[MX], vec[MX], vec1[MX], vec0[MX];
string s[MX];
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> t;
  for (int i = 1; i <= t; i++) {
    int n;
    cin >> n;
    for (int j = 0; j < n; j++) {
      int a;
      cin >> a;
      vec[i].push_back(a);
    }
    cin >> s[i];
    for (int j = 0; j < n; j++) {
      if (s[i][j] == '1') {
        vec1[i].push_back(vec[i][j]);
      } else {
        vec0[i].push_back(vec[i][j]);
      }
    }
    sort(vec0[i].begin(), vec0[i].end());
    sort(vec1[i].begin(), vec1[i].end());
    int cnt0 = vec0[i].size(), cnt1 = vec1[i].size();
    int c1 = 0, c0 = 0;
    for (int j = 0; j < n; j++) {
      if (s[i][j] == '0') {
        int temp = std::lower_bound(vec0[i].begin(), vec0[i].end(), vec[i][j]) -
                   vec0[i].begin();
        ans[i].push_back(temp + 1);
        c0++;
      } else {
        int temp = std::lower_bound(vec1[i].begin(), vec1[i].end(), vec[i][j]) -
                   vec1[i].begin();
        ans[i].push_back(temp + cnt0 + 1);
        c1++;
      }
    }
  }
  for (int i = 1; i <= t; i++) {
    for (int j = 0; j < ans[i].size(); j++) cout << ans[i][j] << " ";
    cout << endl;
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> v[5];
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      int k = s.size();
      vector<int> ch(5);
      for (int j = 0; j < k; j++) {
        ch[s[j] - 'a']++;
      }
      for (int j = 0; j < 5; j++) {
        v[j].push_back(2 * ch[j] - k);
      }
    }
    for (int i = 0; i < 5; i++) {
      sort(v[i].begin(), v[i].end());
    }
    int mx = 0;
    for (int i = 0; i < 5; i++) {
      int k = v[i].size();
      int cnt = 0, sum = 0;
      for (int j = k - 1; j >= 0; j--) {
        sum += v[i][j];
        if (sum > 0) {
          ++cnt;
        } else {
          break;
        }
      }
      mx = max(mx, cnt);
    }
    cout << mx << '\n';
  }
}

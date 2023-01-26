#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v[5];
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      int h[5] = {0};
      for (int j = 0; j < s.size(); j++) {
        h[s[j] - 'a']++;
      }
      for (int j = 0; j < 5; j++) {
        v[j].push_back(2 * h[j] - s.size());
      }
    }
    int maxx = 0;
    for (int i = 0; i < 5; i++) {
      sort(v[i].begin(), v[i].end());
      int curr = 0;
      int cnt = 0;
      for (int j = v[i].size() - 1; j >= 0; j--) {
        if (curr + v[i][j] <= 0)
          break;
        else {
          curr += v[i][j];
          cnt++;
        }
      }
      maxx = max(maxx, cnt);
    }
    cout << maxx << endl;
  }
}

#include <bits/stdc++.h>
using namespace std;
bool compare(vector<long long> &v1, vector<long long> &v2) {
  int cnt1 = 0, cnt2 = 0;
  for (int i = 0; i < 5; ++i) {
    if (v1[i] < v2[i])
      cnt1++;
    else
      cnt2++;
  }
  return cnt1 > cnt2;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k, ans = 0;
    cin >> n >> k;
    vector<int> visited(2 * n + 1, 0);
    vector<vector<int>> set;
    for (int i = 0; i < k; ++i) {
      int a, b;
      cin >> a >> b;
      visited[a] = 1;
      visited[b] = 1;
      for (int j = 0; j < set.size(); ++j) {
        int flag = 0;
        for (int l = min(a, b) + 1; l < max(a, b); ++l) {
          if (l == set[j][0]) {
            flag++;
          } else if (l == set[j][1]) {
            flag++;
          }
        }
        flag = flag % 2;
        if (flag == 1) ans++;
      }
      set.push_back({a, b});
    }
    for (int i = 0; i < set.size(); ++i) {
      int Max = max(set[i][0], set[i][1]), Min = min(set[i][0], set[i][1]),
          cnt1 = 0, cnt2 = 0;
      for (int j = Min + 1; j < Max; ++j) {
        if (visited[j] == 0) cnt1++;
      }
      for (int j = Max + 1; j != Min; j++) {
        if (j == 2 * n + 1) j = 1;
        if (j == Min) break;
        if (visited[j] == 0) cnt2++;
      }
      ans += min(cnt1, cnt2);
    }
    ans += (n - k) * (n - k - 1) / 2;
    cout << ans << endl;
  }
  return 0;
}

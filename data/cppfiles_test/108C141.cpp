#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int T, n;
  cin >> T;
  while (T--) {
    cin >> n;
    vector<pair<int, int>> a(n);
    vector<vector<int>> e(n);
    vector<int> ans(n);
    int maxa = 0, maxb = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i].first;
      a[i].second = i;
    }
    sort(a.begin(), a.end());
    for (int i = 1; i < n; i++) {
      e[a[i - 1].second].push_back(a[i].second);
    }
    for (int i = 0; i < n; i++) {
      cin >> a[i].first;
      a[i].second = i;
    }
    sort(a.begin(), a.end());
    for (int i = 1; i < n; i++) {
      e[a[i - 1].second].push_back(a[i].second);
    }
    queue<int> q;
    ans[a[n - 1].second] = 1;
    q.push(a[n - 1].second);
    while (!q.empty()) {
      int now = q.front();
      q.pop();
      for (auto &t : e[now]) {
        if (ans[t] == 0) {
          ans[t] = 1;
          q.push(t);
        }
      }
    }
    for (int i = 0; i < n; i++) cout << ans[i];
    cout << '\n';
  }
}

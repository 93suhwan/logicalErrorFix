#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    priority_queue<pair<int, int>> q;
    vector<pair<int, int>> ans;
    int n;
    scanf("%d", &n);
    int t;
    for (int i = 0; i < n; i++) {
      scanf("%d", &t);
      if (t) q.push({t, i});
    }
    pair<int, int> a, b;
    while (!q.empty() && q.size() != 1) {
      a = q.top();
      q.pop();
      b = q.top();
      q.pop();
      ans.push_back({a.second, b.second});
      a.first--;
      b.first--;
      if (a.first) q.push(a);
      if (b.first) q.push(b);
    }
    printf("%d\n", int(ans.size()));
    for (int i = 0; i < ans.size(); i++)
      printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
  }
}

#include <bits/stdc++.h>
using namespace std;
const int INF = 10000000;
int f(int x) {
  if (__builtin_popcount(x) == 1) {
    return 0;
  }
  return (1 << (32 - __builtin_clz(x))) - x;
}
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> b;
  for (int i = 0; i < n; i++) {
    int x = a[i];
    while (x > 0) {
      b.push_back(x);
      x = f(x);
    }
  }
  b.push_back(0);
  sort(b.begin(), b.end());
  b.erase(unique(b.begin(), b.end()), b.end());
  for (int i = 0; i < n; i++) {
    a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
  }
  int V = b.size();
  vector<int> p(V, -1);
  for (int i = 1; i < V; i++) {
    p[i] = lower_bound(b.begin(), b.end(), f(b[i])) - b.begin();
  }
  vector<vector<int>> c(V);
  for (int i = 1; i < V; i++) {
    c[p[i]].push_back(i);
  }
  vector<pair<int, int>> dp(V, make_pair(-INF, 0));
  for (int i = 0; i < n; i++) {
    dp[a[i]] = make_pair(0, i);
  }
  int x, y;
  int m = 0;
  for (int i = V - 1; i >= 0; i--) {
    vector<pair<int, int>> A;
    for (int j : c[i]) {
      dp[j].first++;
      A.push_back(dp[j]);
      dp[i] = max(dp[i], dp[j]);
    }
    if (A.size() >= 2) {
      sort(A.begin(), A.end(), greater<pair<int, int>>());
      if (A[0].first + A[1].first > m) {
        m = A[0].first + A[1].first;
        x = A[0].second;
        y = A[1].second;
      }
    }
  }
  cout << x + 1 << ' ' << y + 1 << ' ' << m << endl;
}

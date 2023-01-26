#include <bits/stdc++.h>
using namespace std;
void test_case() {
  cin.ignore();
  int n, m;
  cin >> m >> n;
  vector<vector<int64_t>> p(m, vector<int64_t>(n));
  vector<int64_t> maxVal(n, LLONG_MIN);
  vector<int64_t> shopWithMaxVal(n);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> p[i][j];
      if (maxVal[j] < p[i][j]) {
        maxVal[j] = p[i][j];
        shopWithMaxVal[j] = i;
      }
    }
  }
  set<int64_t> shopsVisited;
  for (int i = 0; i < n; i++) {
    shopsVisited.insert(shopWithMaxVal[i]);
  }
  int64_t minFirstHighest = LLONG_MAX;
  for (int i = 0; i < n; i++) {
    minFirstHighest = min(minFirstHighest, maxVal[i]);
  }
  if (m < n or shopsVisited.size() <= n - 1) {
    cout << minFirstHighest << '\n';
    return;
  }
  int64_t maxSecondHighest = LLONG_MIN;
  for (int i = 0; i < m; i++) {
    sort(p[i].begin(), p[i].end());
    int64_t secondHighest = p[i][n - 2];
    maxSecondHighest = max(maxSecondHighest, secondHighest);
  }
  cout << min(maxSecondHighest, minFirstHighest) << '\n';
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;
  cin >> T;
  while (T--) {
    test_case();
  }
  return 0;
}

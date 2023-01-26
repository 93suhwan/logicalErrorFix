#include <bits/stdc++.h>
using namespace std;
void testCase() {
  int n, m;
  cin >> n >> m;
  vector<int> x(n);
  for (int &it : x) {
    cin >> it;
  }
  vector<string> res(n);
  for (int i = 0; i < n; ++i) {
    cin >> res[i];
  }
  int64_t best = -1;
  vector<int> sol(m);
  for (int mask = 0; mask < (1 << n); ++mask) {
    vector<pair<int, int>> q(m);
    for (int i = 0; i < m; ++i) {
      q[i].second = i;
    }
    int64_t cost = 0;
    for (int i = 0; i < n; ++i) {
      if (mask & (1 << i)) {
        cost += x[i];
        for (int j = 0; j < m; ++j) {
          if (res[i][j] == '1') {
            q[j].first -= 1;
          }
        }
      } else {
        cost -= x[i];
        for (int j = 0; j < m; ++j) {
          if (res[i][j] == '1') {
            q[j].first += 1;
          }
        }
      }
    }
    sort(q.begin(), q.end());
    for (int i = 0; i < m; ++i) {
      cost += (int64_t)(i + 1) * q[i].first;
    }
    if (best < cost) {
      best = cost;
      for (int i = 0; i < m; ++i) {
        sol[q[i].second] = i;
      }
    }
  }
  for (int i = 0; i < m; ++i) {
    cout << sol[i] + 1 << ' ';
  }
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tests;
  cin >> tests;
  for (int tc = 0; tc < tests; ++tc) {
    testCase();
  }
  return 0;
}

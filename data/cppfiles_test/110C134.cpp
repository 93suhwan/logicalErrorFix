#include <bits/stdc++.h>
using namespace std;
long long MOD = 1000000007;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << endl;
  err(++it, args...);
}
void Solve() {
  long long n, k;
  cin >> n;
  vector<long long> understood(n + 1, 0);
  vector<long long> indegree(n + 1, 0);
  vector<vector<int>> adj(n + 1);
  priority_queue<pair<int, int>> next;
  for (int i = 1; i <= n; i++) {
    cin >> indegree[i];
    if (indegree[i] == 0) {
      next.push({-1, -i});
    }
    for (int j = 0; j < indegree[i]; j++) {
      cin >> k;
      adj[k].push_back(i);
    }
  }
  while (!next.empty()) {
    auto xoros = next.top();
    next.pop();
    understood[-xoros.second] = xoros.first;
    for (int y : adj[-xoros.second]) {
      indegree[y]--;
      if (indegree[y] == 0) {
        if (y > -xoros.second) {
          next.push({xoros.first, -y});
        } else {
          next.push({xoros.first - 1, -y});
        }
      }
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    if (understood[i] == 0) {
      cout << -1 << "\n";
      return;
    }
    ans = max(ans, -understood[i]);
  }
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long ntest;
  cin >> ntest;
  for (long long i = 0; i < ntest; i++) {
    Solve();
  }
}

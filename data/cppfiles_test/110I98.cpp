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
  vector<long long> understood(n + 1, -1);
  vector<long long> indegree(n + 1, 0);
  vector<vector<int>> adj(n + 1);
  queue<pair<int, int>> next;
  for (int i = 1; i <= n; i++) {
    cin >> indegree[i];
    if (indegree[i] == 0) {
      next.push({i, 1});
    }
    for (int j = 0; j < indegree[i]; j++) {
      cin >> k;
      adj[k].push_back(i);
    }
  }
  while (!next.empty()) {
    auto x = next.front();
    next.pop();
    understood[x.first] = x.second;
    for (int y : adj[x.first]) {
      indegree[y]--;
      if (indegree[y] == 0) {
        if (y > x.first) {
          next.push({y, x.second});
        } else {
          next.push({y, x.second + 1});
        }
      }
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    if (understood[i] == -1) {
      cout << -1 << "\n";
      return;
    }
    ans = max(ans, understood[i]);
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

#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
vector<long long> topo_sort(const Graph &G) {
  vector<long long> ans;
  long long n = (long long)G.size();
  vector<long long> ind(n);
  for (long long i = 0; i < n; i++) {
    for (auto e : G[i]) {
      ind[e]++;
    }
  }
  queue<long long> que;
  for (long long i = 0; i < n; i++) {
    if (ind[i] == 0) {
      que.push(i);
    }
  }
  while (!que.empty()) {
    long long now = que.front();
    ans.push_back(now);
    que.pop();
    for (auto e : G[now]) {
      ind[e]--;
      if (ind[e] == 0) {
        que.push(e);
      }
    }
  }
  return ans;
}
void solve() {
  long long N;
  cin >> N;
  Graph G(N);
  for (long long i = 0; i < (N); ++i) {
    long long K;
    cin >> K;
    for (long long j = 0; j < (K); ++j) {
      long long A;
      cin >> A;
      A--;
      G[A].push_back(i);
    }
  }
  vector<long long> TS = topo_sort(G);
  if (TS.size() != N) {
    cout << -1 << endl;
    return;
  }
  long long stock = TS[0];
  long long ans = 1;
  for (long long i = 1; i <= (N); ++i) {
    if (TS[i] < stock) {
      stock = TS[i];
      ans++;
    }
  }
  cout << ans << endl;
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  long long t;
  cin >> t;
  for (long long i = 0; i < (t); ++i) solve();
}

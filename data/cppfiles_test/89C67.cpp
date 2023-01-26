#include <bits/stdc++.h>
using namespace std;
long long MOD = 1000000007;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << endl;
  err(++it, args...);
}
long long ans;
vector<vector<long long>> adj;
enum Type { None, Bud, Leaf };
Type dfs(int i, int p) {
  int numchildren = 0;
  for (auto j : adj[i]) {
    if (j == p) {
      continue;
    }
    numchildren++;
    auto t = dfs(j, i);
    if (t == Bud) {
      numchildren--;
    }
  }
  if (numchildren == 0) {
    ans++;
    return Leaf;
  }
  ans--;
  return Bud;
}
void Solve() {
  long long n;
  cin >> n;
  adj = vector<vector<long long>>(n, vector<long long>());
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  ans = 0;
  auto t = dfs(0, -1);
  if (t == Bud) {
    ans++;
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

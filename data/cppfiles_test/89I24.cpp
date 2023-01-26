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
  int numbuds = 0;
  int numleaves = 0;
  for (auto j : adj[i]) {
    if (j == p) {
      continue;
    }
    numchildren++;
    auto t = dfs(j, i);
    if (t == Bud) {
      numbuds++;
    } else if (t == Leaf) {
      numleaves++;
    }
  }
  if (numchildren == 0 || numchildren == numbuds) {
    ans++;
    return Leaf;
  }
  if (numchildren == numleaves) {
    ans--;
    return Bud;
  }
  return None;
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
  dfs(0, -1);
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

#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  std::cout.tie(0);
}
vector<vector<long long> > g;
vector<long long> was;
void dfs(long long x) {
  was[x] = 1;
  bool l = false;
  for (long long y : g[x]) {
    if (was[y] == 0) {
      dfs(y);
      if (was[y] == 1) l = true;
    }
  }
  if (l) was[x] = 2;
}
void solve() {
  long long n;
  cin >> n;
  g.assign(n, vector<long long>());
  was.assign(n, 0);
  for (long long(i) = 0; (i) < (n - 1); (i)++) {
    long long a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(0);
  was[0] = 0;
  bool is = false;
  for (long long y : g[0]) {
    if (was[y] == 1) {
      is = true;
      break;
    }
  }
  long long cnt = 0;
  for (auto x : was) {
    if (x == 2) cnt++;
  }
  cout << n - 2 * cnt - is << '\n';
}
signed main() {
  fast();
  long long t = 1;
  cin >> t;
  for (long long(i) = 0; (i) < (t); (i)++) {
    cout << "test case #" << i << ":\n";
    solve();
  }
  return 0;
}

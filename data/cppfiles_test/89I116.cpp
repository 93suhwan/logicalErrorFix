#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  std::cout.tie(0);
}
vector<vector<long long> > g;
vector<bool> was;
long long cntl = 0, cntp = 0;
bool freel = false;
bool dfs(long long x) {
  was[x] = true;
  bool isp = true;
  bool isl = true;
  bool w = false;
  for (long long y : g[x]) {
    if (!was[y]) {
      isl = false;
      bool res = dfs(y);
      isp &= res;
      if (res) w = true;
    }
  }
  if (isl) {
    cntl++;
    return true;
  }
  if (isp && x != 0) {
    cntp++;
  } else if (w) {
    freel = true;
  }
  return false;
}
void solve() {
  cntl = 0, cntp = 0;
  freel = false;
  long long n;
  cin >> n;
  g.assign(n, vector<long long>());
  was.assign(n, false);
  for (long long(i) = 0; (i) < (n - 1); (i)++) {
    long long a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(0);
  if (!freel) cntp--;
  cout << cntl - cntp << '\n';
}
signed main() {
  fast();
  long long t = 1;
  cin >> t;
  for (long long(i) = 0; (i) < (t); (i)++) {
    solve();
  }
  return 0;
}

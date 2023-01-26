#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")
using namespace std;
mt19937 rnd;
const long long maxn = 3e5 + 50;
const long long mod = 1e9 + 7;
const long long base = 3e18;
long long a[maxn];
long long b[maxn];
vector<long long> adj[maxn];
long long dp[maxn][2];
long long n;
void dosth() {
  set<long long> st;
  for (int i = 1; i <= n; i++) {
    st.insert(i);
    dp[i][0] = base;
    dp[i][1] = base;
  }
  queue<pair<long long, long long> > q;
  q.push(make_pair(n, 0));
  while (!q.empty()) {
    auto p = q.front();
    q.pop();
    long long x = p.first;
    if (p.second == 0) {
      if (x == a[x]) {
        vector<long long> ans;
        pair<long long, long long> nw = make_pair(x, 0);
        ans.push_back(0);
        while (nw.first != n) {
          if (nw.second == 1) ans.push_back(nw.first);
          nw.first = dp[nw.first][nw.second];
          nw.second = 1 - nw.second;
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << "\n";
        for (auto to : ans) cout << to << " ";
        return;
      }
      long long r = x;
      long long l = x - a[x];
      auto it = st.lower_bound(l);
      vector<long long> ers;
      while (it != st.end() && (*it) <= r) {
        long long pos = (*it);
        ers.push_back(pos);
        dp[pos][1] = x;
        q.push(make_pair(pos, 1));
        it++;
      }
      for (auto to : ers) st.erase(to);
    } else {
      if (dp[x + b[x]][0] == base) {
        dp[x + b[x]][0] = x;
        q.push(make_pair(x + b[x], 0));
      }
    }
  }
  cout << -1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  if (fopen("t.inp", "r")) {
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
  }
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  dosth();
}

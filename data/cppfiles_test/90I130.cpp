#include <bits/stdc++.h>
using namespace std;
double PI = 3.14159265359;
long long inf = 1000000000000000007;
long long mod = 1000000007;
long long mod1 = 998244353;
const bool multi = 1;
long long a[200007];
long long l[200007];
long long r[200007];
bool nie[200007];
long long DP[200007];
long long id[200007];
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long tt;
  if (multi)
    cin >> tt;
  else
    tt = 1;
  while (tt--) {
    long long n, m;
    cin >> n >> m;
    vector<pair<long long, long long>> vec;
    for (long long i = 1; i <= n; i++) {
      cin >> a[i];
      a[i] += 1000000000;
      vec.push_back({a[i], 0});
    }
    for (long long i = 1; i <= m; i++) {
      cin >> l[i] >> r[i];
      l[i] += 1000000000;
      r[i] += 1000000000;
      vec.push_back({l[i], -i});
      vec.push_back({r[i], i});
      nie[i] = 0;
      DP[i] = 0;
    }
    sort((vec).begin(), (vec).end());
    set<pair<long long, long long>> act;
    for (auto x : vec) {
      if (x.second < 0)
        act.insert({l[-x.second], -x.second});
      else if (x.second == 0) {
        for (auto y : act) nie[y.second] = 1;
        act.clear();
      } else {
        while ((long long)(act).size() > 0) {
          pair<long long, long long> p = *act.begin();
          if (p.first >= l[x.second]) break;
          nie[p.second] = 1;
          act.erase(p);
        }
        act.erase({l[x.second], x.second});
      }
    }
    long long it = 0;
    long long p1 = inf, p2 = inf, c1 = inf, c2 = inf;
    long long pos = -inf;
    for (auto x : vec) {
      if (nie[abs(x.second)]) continue;
      if (x.second == 0) {
        p1 = min(DP[it + 1], c2 + 2 * x.first);
        p2 = min(DP[it + 1], c1 + x.first);
        DP[it + 1] = min(DP[it + 1], min(p1, p2));
        pos = x.first;
      } else if (x.second < 0) {
        it++;
        id[-x.second] = it;
        DP[it + 1] = min(p1 + x.first - pos, p2 + 2 * (x.first - pos));
      } else {
        c1 = min(c1, DP[id[x.second]] - x.first);
        c2 = min(c2, DP[id[x.second]] - 2 * x.first);
      }
    }
    cout << DP[it + 1] << '\n';
  }
  return 0;
}

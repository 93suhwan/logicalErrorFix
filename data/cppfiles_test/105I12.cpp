#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, long long>> vals[2000005];
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    pair<long long, long long> a[n];
    pair<long long, long long> op[n];
    long long mi[n];
    for (long long i = 0; i < n; i++) {
      cin >> a[i].first >> a[i].second;
      op[i].first = a[i].first;
      op[i].second = a[i].second;
      cin >> mi[i];
    }
    long long rx[n];
    long long taken[n];
    memset(taken, 0, sizeof(taken));
    for (long long i = 0; i < n; i++) {
      long long ll = max((long long)(0), mi[i] - a[i].second);
      long long rr = min(a[i].first, mi[i]);
      taken[i] += ll;
      rr -= ll;
      a[i].first -= ll;
      a[i].second -= (mi[i] - ll);
      rx[i] = rr;
    }
    set<long long> s;
    for (long long i = 0; i < n; i++) {
      auto x = a[i];
      s.insert(x.first + x.second);
      vals[x.first + x.second].push_back({x.first, i});
    }
    long long fina = 0;
    for (auto x : s) {
      sort(vals[x].begin(), vals[x].end());
      auto vv = vals[x];
      long long maxa = 0;
      long long optim_start = 0;
      long long optim_end = 0;
      long long z = vals[x].size();
      long long r = 0;
      for (long long i = 0; i < z; i++) {
        long long l = i;
        r = max(r, i);
        while (r < z && vv[r].first - (rx[vv[r].second]) <= vv[l].first) {
          r++;
        }
        if (r - l > maxa) {
          maxa = r - l;
          optim_start = l;
          optim_end = r;
        }
      }
      fina += (z - maxa + 1);
      for (long long i = optim_start; i < optim_end; i++) {
        taken[vv[i].second] += (vv[i].first - vv[optim_start].first);
      }
    }
    set<pair<long long, long long>> lol;
    for (long long i = 0; i < n; i++) {
      lol.insert({op[i].first - taken[i], op[i].second + taken[i] - mi[i]});
    }
    cout << lol.size() << "\n";
    ;
    for (long long i = 0; i < n; i++) {
      auto x = taken[i];
      cout << x << " " << mi[i] - x << "\n";
    }
    for (auto x : s) {
      vals[x].clear();
    }
  }
}

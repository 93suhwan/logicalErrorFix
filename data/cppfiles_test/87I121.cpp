#include <bits/stdc++.h>
using namespace std;
void debug(vector<long long> v) {
  for (auto t : v)
    cerr << "\033[1m\033[31m" << t << " "
         << "\033[0m";
  cerr << "\n";
}
bool cmp(pair<long long, long long> &a, pair<long long, long long> &b) {
  if (a.first != b.first)
    return a.first < b.first;
  else {
    return a.second < b.second;
  }
}
long long n, m;
vector<long long> v;
void take() {
  cin >> n >> m;
  v.clear();
  v.resize(m);
  for (auto &zz : v) cin >> zz;
}
void solve() {
  take();
  sort(v.begin(), v.end(), greater<long long>());
  vector<pair<long long, long long>> p;
  for (long long i = 0; i < m; i++) p.push_back(make_pair(v[i], i));
  sort(p.begin(), p.end());
  vector<long long> fin(m, -1);
  long long ans = 0;
  for (long long i = 0; i < m; i++) {
    debug(fin);
    for (long long j = 0; j <= p[i].second; j++) {
      if (j == p[i].second)
        fin[j] = p[i].first;
      else if (fin[j] == -1)
        ans++;
    }
  }
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  auto time0 = chrono::high_resolution_clock::now();
  long long t = 1;
  cin >> t;
  for (long long i = 0; i < t; i++) {
    solve();
  }
}

#include <bits/stdc++.h>
using namespace std;
int ttt = 1;
long long n, m, k;
long long const MAXN = 2e5 + 5;
vector<long long> par(MAXN), Size(MAXN), min_(MAXN);
long long find(long long a) {
  if (a != par[a]) par[a] = find(par[a]);
  return par[a];
}
void Union(long long u, long long v) {
  u = find(u);
  v = find(v);
  if (u == v) return;
  if (Size[u] > Size[v]) swap(u, v);
  par[u] = v;
  Size[v] += Size[u];
  min_[v] = min(min_[v], min_[u]);
  return;
}
template <class myType>
void print_arr(myType &arr, long long L, string sep) {
  for (long long(i) = (0); (i) < (L); ++(i)) {
    cout << arr[i] << (i < L - 1 ? " " : "\n");
  }
  return;
}
void solve() {
  cin >> n >> k;
  map<long long, vector<pair<long long, long long>>> rows;
  map<long long, vector<pair<long long, long long>>> cols;
  iota(par.begin(), par.begin() + n, 0LL);
  for (long long(i) = (0); (i) < (n); ++(i)) Size[i] = 1;
  for (long long(i) = (0); (i) < (n); ++(i)) {
    long long x, y, t;
    cin >> x >> y >> t;
    rows[x].push_back(make_pair(y, i));
    cols[y].push_back(make_pair(x, i));
    min_[i] = t;
  }
  for (pair<long long, vector<pair<long long, long long>>> p : rows) {
    sort(rows[p.first].begin(), rows[p.first].end());
    for (int i = 0; i < p.second.size() - 1; i++) {
      if (p.second[i + 1].first - p.second[i].first <= k) {
        Union(p.second[i + 1].second, p.second[i].second);
      }
    }
  }
  for (pair<long long, vector<pair<long long, long long>>> p : cols) {
    sort(cols[p.first].begin(), cols[p.first].end());
    for (int i = 0; i < p.second.size() - 1; i++) {
      if (p.second[i + 1].first - p.second[i].first <= k) {
        Union(p.second[i + 1].second, p.second[i].second);
      }
    }
  }
  vector<long long> times;
  for (long long(i) = (0); (i) < (n); ++(i)) {
    if (find(i) == i) times.push_back(min_[i]);
  }
  sort(times.begin(), times.end());
  long long L = -1, R = n + 1;
  while (R - L > 1) {
    long long M = (L + R) >> 1;
    long long cnt = 0;
    for (long long(i) = (0); (i) < (times.size()); ++(i)) {
      if (times[i] > M) cnt++;
    }
    if (cnt > M + 1)
      L = M;
    else
      R = M;
  }
  cout << R << "\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> ttt;
  while (ttt--) solve();
  return 0;
}

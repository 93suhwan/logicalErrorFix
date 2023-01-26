#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2e5 + 4;
const long long nax = 2e5 + 2;
const long long max_val = 5e4 + 10;
const long long mod = 998244353;
const long long bits = 18;
long long caseNumber = 1;
vector<int> siz(maxn), par(maxn);
int find_set(int v) {
  if (v == par[v]) return v;
  return par[v] = find_set(par[v]);
}
void union_sets(int a, int b) {
  a = find_set(a);
  b = find_set(b);
  if (a != b) {
    if (siz[a] < siz[b]) swap(a, b);
    par[b] = a;
    siz[a] += siz[b];
  }
}
void solve() {
  int n, k;
  cin >> n >> k;
  map<pair<int, int>, int> ind;
  map<int, vector<int> > for_x, for_y;
  vector<pair<int, int> > v(n);
  vector<int> ti(n);
  for (int i = 0; i < n; i++) {
    par[i] = i;
    siz[i] = 1;
    cin >> v[i].first >> v[i].second >> ti[i];
    for_x[v[i].first].push_back(v[i].second);
    for_y[v[i].second].push_back(v[i].first);
    ind[v[i]] = i;
  }
  for (auto &x : for_x) sort(x.second.begin(), x.second.end());
  for (auto &x : for_y) sort(x.second.begin(), x.second.end());
  for (auto &x : for_x) {
    for (int j = 1; j < x.second.size(); j++) {
      long long dist = abs(1LL * x.second[j] - 1LL * x.second[j - 1]);
      if (dist <= 1LL * k) {
        union_sets(ind[make_pair(x.first, x.second[j])],
                   ind[make_pair(x.first, x.second[j - 1])]);
      }
    }
  }
  for (auto &x : for_y) {
    for (int j = 1; j < x.second.size(); j++) {
      long long dist = abs(1LL * x.second[j] - 1LL * x.second[j - 1]);
      if (dist <= 1LL * k) {
        union_sets(ind[make_pair(x.second[j], x.first)],
                   ind[make_pair(x.second[j - 1], x.first)]);
      }
    }
  }
  set<int> all_pars;
  for (int i = 0; i < n; i++) {
    all_pars.insert(find_set(i));
  }
  auto check = [&](int m) {
    set<int> curr;
    for (int i = 0; i < n; i++) {
      if (ti[i] <= m) {
        curr.insert(find_set(i));
      }
    }
    int done = 0;
    int aaa = curr.size();
    int bbb = all_pars.size();
    if (bbb - aaa <= m + 1) {
      return true;
    }
    return false;
  };
  int l = 0, r = 1e9;
  while (r - l > 1) {
    int mid = (l + (r - l) / 2);
    if (check(mid)) {
      r = mid;
    } else
      l = mid;
  }
  if (check(l)) {
    cout << l << "\n";
  } else
    cout << r << "\n";
}
bool TestCase1 = 1;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  t = 1;
  if (TestCase1) {
    cin >> t;
  }
  int cnt = 1;
  while (t--) {
    solve();
    cnt++;
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const long long N = 5e5 + 10;
const long long M = 1e6 + 11;
const long long big = 1e17;
const long long hsh2 = 1964325029;
const long long mod = 1e9 + 7;
const double EPS = 1e-9;
const long long block = 1e14;
const long long shift = 2e3;
const double pi = acos(-1.0);
mt19937 bruh(chrono::steady_clock::now().time_since_epoch().count());
long long n;
struct dsu {
  long long p[N], sz[N];
  set<long long> comp;
  void init() {
    for (int i = 1; i <= n; i++) p[i] = i, sz[i] = 1, comp.insert(i);
  }
  long long fnd(long long a) { return (p[a] = (p[a] == a ? a : fnd(p[a]))); }
  void unt(long long a, long long b) {
    a = fnd(a), b = fnd(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    comp.erase(b);
    sz[a] += sz[b];
    p[b] = a;
  }
} rt[2];
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  rt[0].init();
  rt[1].init();
  long long m[2] = {0};
  cin >> m[0] >> m[1];
  long long sm[2] = {m[0], m[1]};
  while (m[0]--) {
    long long a, b;
    cin >> a >> b;
    rt[0].unt(a, b);
  }
  while (m[1]--) {
    long long a, b;
    cin >> a >> b;
    rt[1].unt(a, b);
  }
  vector<pair<long long, long long> > ans;
  while (sm[0] < n - 1 && sm[1] < n - 1) {
    long long i = bruh() % n + 1, j = bruh() % n + 1;
    auto it = rt[0].comp.lower_bound(i), it2 = rt[1].comp.lower_bound(j);
    if (it == rt[0].comp.end()) it--;
    if (it2 == rt[1].comp.end()) it2--;
    i = *it, j = *it2;
    if (rt[0].fnd(i) != rt[0].fnd(j) && rt[1].fnd(i) != rt[1].fnd(j)) {
      sm[0]++, sm[1]++;
      rt[0].unt(i, j);
      rt[1].unt(i, j);
      ans.push_back(make_pair(i, j));
    }
  }
  cout << ans.size() << '\n';
  for (auto u : ans) cout << u.first << " " << u.second << '\n';
}

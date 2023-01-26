#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
const int N = 4 * 1e5 + 10;
const long double eps = 1e-9;
const int mod = 998244353;
int cnt[N], p[N], siz[N], indmax[N];
long long pref[N], ans[N];
pair<int, int> q[N];
vector<pair<int, int> > t;
set<pair<int, int> > st;
long long res = 0;
int fndp(int x) {
  if (p[x] == x) return x;
  return p[x] = fndp(p[x]);
}
void upd(int a) {
  int b = fndp(a + 1);
  a = fndp(a);
  if (a == b) return;
  if (siz[a] < siz[b]) swap(a, b);
  res -= pref[indmax[a]] - pref[indmax[a] - cnt[a]];
  res -= pref[indmax[b]] - pref[indmax[b] - cnt[b]];
  indmax[a] = max(indmax[a], indmax[b]);
  cnt[a] += cnt[b];
  siz[a] += siz[b];
  p[b] = a;
  res += pref[indmax[a]] - pref[indmax[a] - cnt[a]];
  return;
}
void update(int k) {
  auto it = st.begin(), it2 = it;
  while (!(it == st.end() || (*it).first > k)) {
    upd((*it).second);
    it2 = it;
    ++it2;
    st.erase(it);
    it = it2;
  }
}
void solve() {
  int n, m, tt;
  cin >> n >> m >> tt;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    t.push_back({a, 1});
  }
  for (int i = 0; i < m; ++i) {
    int a;
    cin >> a;
    t.push_back({a, 0});
  }
  sort(t.begin(), t.end());
  n += m;
  pref[0] = 0;
  for (int i = 0; i < n; ++i) {
    if (i != n - 1) st.insert({t[i + 1].first - t[i].first, i});
    pref[i + 1] = pref[i] + t[i].first;
    p[i] = i;
    siz[i] = 1;
    indmax[i] = i + 1;
    cnt[i] = t[i].second;
    if (t[i].second == 1) res += t[i].first;
  }
  for (int i = 0; i < tt; ++i) {
    cin >> q[i].first;
    q[i].second = i;
  }
  sort(q, q + tt);
  for (int i = 0; i < tt; ++i) {
    update(q[i].first);
    ans[q[i].second] = res;
  }
  for (int i = 0; i < tt; ++i) cout << ans[i] << "\n";
  cout << "\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) solve();
  return 0;
}

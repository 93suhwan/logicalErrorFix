#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pair<int, int>>;
using vvi = vector<vi>;
int Bit(int mask, int b) { return (mask >> b) & 1; }
template <class T>
bool ckmin(T &a, const T &b) {
  if (b < a) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
bool ckmax(T &a, const T &b) {
  if (b > a) {
    a = b;
    return true;
  }
  return false;
}
void solve() {
  int n, m, q;
  cin >> n >> m >> q;
  vpi a(n), b(m);
  for (int i = 0; i < (n); ++i) cin >> a[i].first;
  for (int i = 0; i < (m); ++i) cin >> b[i].first;
  for (int i = 0; i < (n); ++i) a[i].second = 0;
  for (int i = 0; i < (m); ++i) b[i].second = 1;
  sort((a).begin(), (a).end());
  sort((b).begin(), (b).end());
  vpi c(n + m);
  merge((a).begin(), (a).end(), (b).begin(), (b).end(), c.begin());
  vector<int> r(n + m - 1);
  iota((r).begin(), (r).end(), 1);
  sort((r).begin(), (r).end(), [&](const int &i, const int &j) {
    return c[i].first - c[i - 1].first < c[j].first - c[j - 1].first;
  });
  vector<ll> pref(n + m + 1);
  for (int i = 0; i < (n + m); ++i) pref[i + 1] = pref[i] + c[i].first;
  ll cur = 0;
  for (int i = 0; i < (n); ++i) cur += a[i].first;
  vector<pair<ll, ll>> answers;
  map<int, int> cnt;
  for (int i = 0; i < (n + m); ++i) {
    if (c[i].second == 0)
      cnt[i] = 1;
    else
      cnt[i] = 0;
  }
  auto get = [&](int i) {
    auto it = cnt.upper_bound(i);
    int l = i;
    int r = n + m;
    if (it != cnt.end()) r = it->first;
    int x = cnt[i];
    return pref[r] - pref[r - x];
  };
  answers.emplace_back(0, cur);
  for (auto &i : r) {
    ll rz = c[i].first - c[i - 1].first;
    auto it = cnt.find(i);
    it--;
    int j = it->first;
    cur -= get(i) + get(j);
    cnt[j] += cnt[i];
    cnt.erase(i);
    cur += get(j);
    answers.emplace_back(rz, cur);
  }
  for (int _ = 0; _ < (q); ++_) {
    int k;
    cin >> k;
    pair<ll, ll> tmp = {k + 1, -1};
    int j =
        lower_bound((answers).begin(), (answers).end(), tmp) - answers.begin();
    j--;
    cout << answers[j].second << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  for (int _ = 0; _ < (t); ++_) {
    solve();
  }
  return 0;
}

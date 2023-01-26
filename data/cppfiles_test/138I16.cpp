#include <bits/stdc++.h>
using namespace std;
const long long intmax = 2147483647;
const long long intmin = -2147483648;
const long long mod = 1000000007;
const long long mod2 = 998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <typename T>
istream &operator>>(istream &in, vector<T> &v) {
  for (auto &i : v) in >> i;
  return in;
}
template <typename T>
ostream &operator<<(ostream &ost, vector<T> v) {
  if (&ost == &cerr) {
    cerr << "{";
    long long cnt = v.size();
    for (auto x : v) {
      cerr << x;
      cnt--;
      if (cnt) cerr << ", ";
    }
    cerr << "}";
  } else
    for (auto i : v) ost << i << " ";
  return ost;
}
template <typename T>
ostream &operator<<(ostream &ost, set<T> s) {
  if (&ost == &cerr) {
    cerr << "{";
    long long cnt = s.size();
    for (auto x : s) {
      cerr << x;
      cnt--;
      if (cnt) cerr << ", ";
    }
    cerr << "}";
  } else
    for (auto i : s) ost << i << " ";
  return ost;
}
template <typename U, typename V>
ostream &operator<<(ostream &ost, map<U, V> &m) {
  if (&ost == &cerr) {
    cerr << "{";
    long long cnt = m.size();
    for (auto x : m) {
      cerr << x;
      cnt--;
      if (cnt) cerr << ", ";
    }
    cerr << "}";
  } else
    for (auto i : m) ost << i;
  return ost;
}
template <typename U, typename V>
istream &operator>>(istream &in, pair<U, V> &p) {
  in >> p.first >> p.second;
  return in;
}
template <typename U, typename V>
ostream &operator<<(ostream &ost, pair<U, V> p) {
  if (&ost == &cerr)
    ost << "{" << p.first << ": " << p.second << "}";
  else
    ost << p.first << " " << p.second << " ";
  return ost;
}
ostream &operator<<(ostream &ost, __int128_t x) {
  string output = "";
  while (x) output += '0' + x % 10, x /= 10;
  reverse(output.begin(), output.end());
  ost << output;
  return ost;
}
istream &operator>>(istream &in, __int128_t &x) {
  x = 0;
  string num;
  cin >> num;
  for (char c : num) x *= 10, x += c - '0';
  return in;
}
template <typename... T>
void read(T &...args) {
  ((cin >> args), ...);
}
template <typename... T>
void print(T... args) {
  ((cout << args << " "), ...);
  cout << '\n';
}
long long ans = 0;
long long root[200005], sz[200005];
vector<long long> pref;
long long fr(long long x) {
  if (root[x] == x)
    return x;
  else
    return root[x] = fr(root[x]);
}
void su(long long u, long long v) {
  if (fr(u) == fr(v)) return;
  u = fr(u), v = fr(v);
  if (u < v) swap(u, v);
  ans -= pref[u];
  if (u - sz[u] >= 0) ans += pref[u - sz[u]];
  ans -= pref[v];
  if (v - sz[v] >= 0) ans += pref[v - sz[v]];
  sz[u] += sz[v];
  sz[v] = 0;
  root[v] = root[u];
  ans += pref[u];
  if (u - sz[u] >= 0) ans -= pref[u - sz[u]];
}
void solve() {
  long long n, m, q;
  cin >> n >> m >> q;
  vector<long long> a(n), b(m), v(n + m);
  vector<pair<long long, long long>> query(q);
  for (long long i = 0; i < n; i++) cin >> a[i], v[i] = a[i];
  for (long long i = 0; i < m; i++) cin >> b[i], v[i + n] = b[i];
  for (long long i = 0; i < q; i++) cin >> query[i].first, query[i].second = i;
  vector<long long> answer(q);
  sort(v.begin(), v.end());
  sort(query.begin(), query.end());
  sort(a.begin(), a.end());
  pref = v;
  for (long long i = 1; i < pref.size(); i++) pref[i] += pref[i - 1];
  vector<long long> diff(n + m - 1);
  set<pair<long long, long long>> s;
  for (long long i = 0; i < n + m; i++) root[i] = i, sz[i] = 0;
  long long j = 0;
  for (long long i = 0; i < a.size(); i++) {
    while (a[i] != v[j]) j++;
    sz[j] = 1;
    j++;
  }
  for (long long i = 0; i < n + m - 1; i++)
    diff[i] = v[i + 1] - v[i], s.insert({diff[i], i});
  for (long long i = 0; i < n; i++) ans += a[i];
  set<pair<long long, long long>>::iterator it = s.begin();
  for (long long i = 0; i < q; i++) {
    auto end = s.upper_bound({query[i].first, intmax});
    while (it != end) {
      su(it->second, it->second + 1);
      ++it;
    }
    answer[i] = ans;
  }
  for (auto i : answer) cout << i << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  for (long long var = 1; var < t + 1; var++) solve();
  return 0;
}

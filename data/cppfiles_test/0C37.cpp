#include <bits/stdc++.h>
using namespace std;
using lld = long double;
using ll = long long int;
using ar = vector<ll>;
using mat = vector<vector<ll>>;
mat cn(ll n, ll m) { return vector<vector<ll>>(n, vector<ll>(m)); }
ll const MOD = 1000000007;
template <class T>
inline bool chmin(T &a, T b) {
  return a > b ? a = b, 1 : 0;
}
template <class T>
inline bool chmadp2(T &a, T b) {
  return a < b ? a = b, 1 : 0;
}
template <class T>
inline void add(T &a, T b) {
  a += b;
  a >= MOD ? a - MOD : a;
}
template <class T>
inline void sub(T &a, T b) {
  a -= b;
  a < 0 ? a + MOD : a;
}
template <class T>
inline void mul(T &a, T b) {
  return (a * b) % MOD;
}
template <typename T>
ostream &operator<<(ostream &out, const vector<T> &v) {
  for (auto &dp2 : v) out << dp2 << ' ';
  return out;
}
template <class T>
void remDup(vector<T> &v) {
  sort((v).begin(), (v).end());
  v.erase(unique((v).begin(), (v).end()), end(v));
}
bool comp1(char &s1, char &s2) { return s1 > s2; }
bool comp2(const pair<ll, pair<ll, ll>> &a, const pair<ll, pair<ll, ll>> &b) {
  if (a.first > b.first) return 1;
  if (a.first == b.first && a.second.second > b.second.second) return 1;
  return 0;
}
class Pair {
 public:
  ll first, second;
};
bool comp3(const Pair &a, const Pair &b) {
  if (a.first > b.first) return 1;
  return 0;
}
class Trips {
 public:
  ll first, second, third;
};
bool comp4(const Trips &a, const Trips &b) {
  if (a.third > b.third) return 1;
  return 0;
}
void readArray(ll a[], int n) {
  for (ll i = 0; i < n; i++) cin >> a[i];
}
ll const inf = 1e9 + 7;
ll const maxn = 5e5 + 1;
bool comp(string &a, string &b) {
  ll m = a.size();
  for (int i = 0; i < m; i++) {
    if (a[i] != b[i]) {
      if (i & 1) {
        if (a[i] < b[i])
          return 0;
        else
          return 1;
      } else {
        if (a[i] < b[i])
          return 1;
        else
          return 0;
      }
    }
  }
  return 0;
}
void solve() {
  ll t1 = 1;
  for (ll tt = 1; tt <= t1; tt++) {
    ll n, m;
    cin >> n >> m;
    unordered_map<string, ll> pos;
    string s[n];
    for (ll i = 0; i < n; i++) {
      cin >> s[i];
      pos[s[i]] = i + 1;
    }
    sort(s, s + n, comp);
    for (ll i = 0; i < n; i++) cout << pos[s[i]] << " ";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
  return 0;
}

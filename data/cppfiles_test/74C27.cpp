#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using uint = unsigned int;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;
using ld = long double;
template <typename T>
void _(const char* s, T h) {
  cerr << s << " = " << h << "\n";
}
template <typename T, typename... Ts>
void _(const char* s, T h, Ts... t) {
  int b = 0;
  while (((b += *s == '(') -= *s == ')') != 0 || *s != ',') cerr << *s++;
  cerr << " = " << h << ",";
  _(s + 1, t...);
}
struct init {
  init() {
    cin.tie(0);
    iostream::sync_with_stdio(0);
    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(5);
  }
  ~init() {}
} init;
template <typename T, typename U>
void upx(T& x, U y) {
  if (x < y) x = y;
}
template <typename T, typename U>
void upn(T& x, U y) {
  if (x > y) x = y;
}
mt19937 rng(300);
const ll N = 1010, C = 1e6 + 6;
ll b[N];
void no() {
  cout << "NO\n";
  exit(0);
}
vector<ll> v[2];
ll n, sum = 0;
vector<ll> o;
unordered_map<ll, vector<ll>> mp;
void yes(vector<ll> u) {
  cout << "YES\n";
  ll val = 0;
  for (ll i = 0; i < (((ll)(u).size())); ++i) {
    for (ll j = 0; j < (2); ++j) {
      cout << val << ' ';
      if (j)
        val = b[o[i]] - val;
      else
        val = b[u[i]] - val;
    }
  }
  set<ll> us;
  for (ll i = 0; i < (((ll)(o).size())); ++i) {
    us.insert(o[i]);
    us.insert(u[i]);
  }
  for (ll i = 0; i < (n); ++i) {
    if (us.count(i)) continue;
    cout << b[i] << ' ';
  }
  cout << '\n';
  exit(0);
}
void gen(ll k, ll i) {
  if (((ll)(o).size()) == k) {
    if (mp.find(sum) == mp.end()) {
      mp[sum] = o;
    } else {
      yes(mp[sum]);
    }
    return;
  }
  if (i == n) return;
  ll r = n - i, need = k - ((ll)(o).size());
  o.emplace_back(i);
  sum += b[i];
  gen(k, i + 1);
  o.pop_back();
  sum -= b[i];
  if (n - i - 1 >= k - ((ll)(o).size())) gen(k, i + 1);
}
int32_t main() {
  cin >> n;
  for (ll i = 0; i < (n); ++i) {
    cin >> b[i];
  }
  sort(b, b + n);
  if (n == 2) {
    if (b[0] != b[1]) no();
    cout << "YES\n0 " << b[0] << '\n';
    return 0;
  }
  for (ll i = 0; i < (n); ++i) {
    v[b[i] % 2].emplace_back(i);
  }
  vector<ll> first;
  if (((ll)(v[0]).size()) >= 3) {
    for (ll i = 0; i < (3); ++i) first.emplace_back(v[0][i]);
  } else if (((ll)(v[1]).size()) >= 2 && ((ll)(v[0]).size()) >= 1) {
    first.emplace_back(v[0][0]);
    first.emplace_back(v[1][0]);
    first.emplace_back(v[1][1]);
  } else {
    for (ll i = 1; i <= n; ++i) {
      mp.clear();
      gen(i, 0);
    }
    no();
  }
  ll second = 0;
  for (ll i = 0; i < (3); ++i) second += b[first[i]];
  second /= 2;
  cout << "YES\n";
  ll val = second - b[first[0]];
  for (ll i = 0; i < (3); ++i) {
    cout << second - b[first[i]] << ' ';
  }
  for (ll i = 0; i < (n); ++i) {
    ll ok = 1;
    for (ll j : first) ok &= j != i;
    if (!ok) continue;
    cout << b[i] - val << ' ';
  }
  cout << '\n';
  return 0;
}

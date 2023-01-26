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
void no() {
  cout << "NO\n";
  exit(0);
}
const ll N = 1010, C = 2e6 + 6;
ll a[N], b[N];
vector<ll> v[2];
vector<pll> sum[C];
int32_t main() {
  ll n;
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
  if (n == 3) {
    if (b[0] == b[1]) {
      cout << "YES\n";
      cout << "0 " << b[1] << ' ' << b[2] << '\n';
      return 0;
    }
    if (b[1] == b[2]) {
      cout << "YES\n";
      cout << "0 " << b[1] << ' ' << b[0] << '\n';
      return 0;
    }
    ll second = b[0] + b[1] + b[2];
    if (second & 1) no();
    second /= 2;
    cout << "YES\n";
    for (ll i = 0; i < (3); ++i) cout << second - b[i] << ' ';
    cout << '\n';
    return 0;
  }
  for (ll i = 0; i < (n); ++i) {
    v[b[i] % 2].emplace_back(i);
  }
  vector<ll> first;
  if (((ll)(v[0]).size()) >= 3) {
    for (ll i = 0; i < (3); ++i) {
      first.emplace_back(v[0].back());
      v[0].pop_back();
    }
  } else if (((ll)(v[1]).size()) >= 2 && ((ll)(v[0]).size()) >= 1) {
    for (ll i = 0; i < (1); ++i) {
      first.emplace_back(v[0].back());
      v[0].pop_back();
    }
    for (ll i = 0; i < (2); ++i) {
      first.emplace_back(v[1].back());
      v[1].pop_back();
    }
  } else {
    for (ll i = 0; i < (n - 1); ++i) {
      if (b[i] == b[i + 1]) {
        cout << "YES\n";
        cout << b[i] << " 0 ";
        for (ll j = 0; j < (n); ++j) {
          if (i == j || j == i + 1) continue;
          cout << b[j] << ' ';
        }
        cout << '\n';
        return 0;
      }
    }
    for (ll i = 0; i < (n); ++i) {
      for (ll j = 0; j < (i); ++j) {
        for (pll p : sum[b[i] + b[j]]) {
          if (i != p.first && i != p.second && j != p.first && j != p.second) {
            cout << "YES\n";
            cout << 0 << ' ' << b[p.first] << ' ' << b[i] - b[p.first] << ' '
                 << b[j] << ' ';
            for (ll k = 0; k < (n); ++k) {
              if (k == i || k == j || k == p.first || k == p.second) continue;
              cout << b[k] << ' ';
            }
            cout << '\n';
            return 0;
          }
        }
        sum[b[i] + b[j]].emplace_back(i, j);
      }
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

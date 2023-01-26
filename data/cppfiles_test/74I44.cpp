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
vector<ll> a;
void check(ll n) {
  set<ll> sums;
  for (ll i = 0; i < (((ll)(a).size())); ++i)
    for (ll j = 0; j < (i); ++j) sums.insert(a[i] + a[j]);
  for (ll i = 0; i < (n); ++i) assert(sums.count(b[i]));
}
void no() {
  cout << "NO\n";
  exit(0);
}
vector<ll> v[2];
pll sum[C * 2];
struct tri {
  ll x, y, z;
  tri() = default;
};
bool operator==(const tri& p1, const tri& p2) {
  return p1.x == p2.x && p1.y == p2.y && p1.z == p2.z;
}
tri sum3[C * 3];
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
        if (sum[b[i] + b[j]] == pll{0, 0}) {
          sum[b[i] + b[j]] = {i, j};
          continue;
        }
        ll x = sum[b[i] + b[j]].first, y = sum[b[i] + b[j]].second;
        ;
        cout << "YES\n";
        cout << 0 << ' ' << b[x] << ' ' << b[i] - b[x] << ' ' << b[j] << ' ';
        for (ll k = 0; k < (n); ++k) {
          if (k == i || k == j || k == x || k == y) continue;
          cout << b[k] << ' ';
        }
        cout << '\n';
        return 0;
      }
    }
    for (ll i = 0; i < (n); ++i) {
      for (ll j = 0; j < (i); ++j) {
        for (ll k = 0; k < (j); ++k) {
          if (sum3[b[i] + b[j] + b[k]] == tri{0, 0, 0}) {
            sum3[b[i] + b[j] + b[k]] = {i, j, k};
            continue;
          }
          tri t = sum3[b[i] + b[j] + b[k]];
          ll x = t.x, y = t.y, z = t.z;
          ;
          cout << "YES\n";
          cout << 0 << ' ' << b[x] << ' ' << b[i] - b[x] << ' '
               << b[y] - b[i] + b[x] << ' ' << b[j] - b[y] + b[i] - b[x] << ' '
               << b[z] - b[j] + b[y] - b[i] + b[x] << '\n';
          for (ll kk = 0; kk < (n); ++kk) {
            if (kk == i || kk == j || kk == x || kk == y || kk == k || kk == z)
              continue;
            cout << b[kk] << ' ';
          }
          cout << '\n';
          return 0;
        }
      }
    }
    ll nn = min(n, 21ll);
    map<pll, ll> w;
    for (ll mask = 0; mask < (1 << nn); ++mask) {
      if (!mask) continue;
      ll sum = 0;
      for (ll i = 0; i < (nn); ++i) {
        if (mask >> i & 1) sum += b[i];
      }
      ll ww = w[{__builtin_popcount(mask), sum}];
      if (!ww) {
        w[{__builtin_popcount(mask), sum}] = mask;
        continue;
      }
      ll com = ww & mask;
      vector<ll> v1, v2;
      set<ll> used;
      for (ll i = 0; i < (nn); ++i) {
        if ((ww ^ com) >> i & 1) {
          v1.emplace_back(i);
        }
        if ((mask ^ com) >> i & 1) {
          v2.emplace_back(i);
        }
        used.insert(i);
      }
      ll z = ((ll)(v1).size());
      ll val = 0;
      cout << "YES\n";
      for (ll i = 0; i < (z); ++i) {
        for (ll j = 0; j < (2); ++j) {
          cout << val << ' ';
          if (j)
            val = v1[i] - val;
          else
            val = v2[i] - val;
        }
      }
      for (ll i = 0; i < (n); ++i) {
        if (used.count(i)) continue;
        cout << b[i] << ' ';
      }
      cout << '\n';
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

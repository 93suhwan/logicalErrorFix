#include <bits/stdc++.h>
#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
using ll = long long;
using datas = pair<ll, ll>;
using ddatas = pair<long double, long double>;
using tdata = pair<ll, datas>;
using vec = vector<ll>;
using mat = vector<vec>;
using pvec = vector<datas>;
using pmat = vector<pvec>;
constexpr ll mod = 998244353;
constexpr ll inf = 1LL << 60;
constexpr long double eps = 1e-9;
const long double PI = acosl(-1);
template <class T, class E>
ostream& operator<<(ostream& os, const pair<T, E>& p) {
  return os << "(" << p.first << "," << p.second << ")";
}
template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  os << "{";
  bool f = false;
  for (auto& x : v) {
    if (f) os << ",";
    os << x;
    f = true;
  }
  os << "}";
  return os;
}
template <class T>
ostream& operator<<(ostream& os, const set<T>& v) {
  os << "{";
  bool f = false;
  for (auto& x : v) {
    if (f) os << ",";
    os << x;
    f = true;
  }
  os << "}";
  return os;
}
template <class T>
ostream& operator<<(ostream& os, const multiset<T>& v) {
  os << "{";
  bool f = false;
  for (auto& x : v) {
    if (f) os << ",";
    os << x;
    f = true;
  }
  os << "}";
  return os;
}
template <class T, class E>
ostream& operator<<(ostream& os, const map<T, E>& v) {
  os << "{";
  bool f = false;
  for (auto& x : v) {
    if (f) os << ",";
    os << x;
    f = true;
  }
  os << "}";
  return os;
}
template <class T>
inline bool chmax(T& a, const T b) {
  bool x = a < b;
  if (x) a = b;
  return x;
}
template <class T>
inline bool chmin(T& a, const T b) {
  bool x = a > b;
  if (x) a = b;
  return x;
}
inline void startupcpp(void) noexcept {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
}
ll N;
ll solve1(pvec a, pvec b, pvec c) {
  ll ok = 0, ng = N + 1;
  sort((a).begin(), (a).end());
  sort((b).begin(), (b).end(),
       [](datas l, datas r) { return l.second < r.second; });
  while (ng - ok > 1) {
    ll mid = (ok + ng) / 2;
    ll axmax = a[mid - 1].first;
    ll i, cnt = 0;
    for (i = 0; i < (ll)N; ++i) {
      if (b[i].first <= axmax) continue;
      ++cnt;
      if (cnt == mid) break;
    }
    if (i == N) {
      ng = mid;
      continue;
    }
    ll bymax = b[i].second;
    cnt = 0;
    for (i = 0; i < (ll)N; ++i) {
      if (c[i].first <= axmax || c[i].second <= bymax) continue;
      ++cnt;
      if (cnt == mid) break;
    }
    if (i == N) {
      ng = mid;
      continue;
    }
    ok = mid;
  }
  return ok;
}
ll solve2(pvec a, pvec b, pvec c) {
  sort((a).begin(), (a).end());
  sort((b).begin(), (b).end());
  sort((c).begin(), (c).end());
  ll ok = 0, ng = N + 1;
  while (ng - ok > 1) {
    ll mid = (ok + ng) / 2;
    ll axmax = a[mid - 1].first;
    ll i, cnt = 0;
    for (i = 0; i < (ll)N; ++i) {
      if (b[i].first <= axmax) continue;
      ++cnt;
      if (cnt == mid) break;
    }
    if (i == N) {
      ng = mid;
      continue;
    }
    ll bxmax = b[i].first;
    cnt = 0;
    for (i = 0; i < (ll)N; ++i) {
      if (c[i].first <= bxmax) continue;
      ++cnt;
      if (cnt == mid) break;
    }
    if (i == N) {
      ng = mid;
      continue;
    }
    ok = mid;
  }
  return ok;
}
int main() {
  startupcpp();
  cin >> N;
  pvec v[3];
  ll i, x, y;
  for (i = 0; i < (ll)N; ++i) {
    ll c;
    cin >> x >> y >> c;
    v[c - 1].emplace_back(x, y);
  }
  N /= 3;
  ll ch, ans = 0;
  for (ch = 0; ch < (ll)2; ++ch) {
    for (x = 0; x < (ll)2; ++x) {
      for (y = 0; y < (ll)2; ++y) {
        vec p = {0, 1, 2};
        do {
          chmax(ans, solve1(v[p[0]], v[p[1]], v[p[2]]));
          chmax(ans, solve2(v[p[0]], v[p[1]], v[p[2]]));
        } while (next_permutation((p).begin(), (p).end()));
        for (i = 0; i < (ll)3; ++i)
          for (auto& x : v[i]) x.second = -x.second;
      }
      for (i = 0; i < (ll)3; ++i)
        for (auto& x : v[i]) x.first = -x.first;
    }
    for (i = 0; i < (ll)3; ++i)
      for (auto& x : v[i]) swap(x.first, x.second);
  }
  cout << ans * 3 << "\n";
}

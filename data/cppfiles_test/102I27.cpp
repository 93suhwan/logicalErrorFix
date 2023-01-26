#include <bits/stdc++.h>
using namespace std;
void Err() {}
template <class T, class... A>
void Err(T a, A... x) {
  cerr << a << ',';
  Err(x...);
}
template <class X, class Y, class... A>
void Err(pair<X, Y> a, A... x) {
  cerr << '(' << a.first << ',' << a.second << ')';
  Err(x...);
}
template <template <class...> class T, class t, class... A>
void Err(T<t> a, A... x) {
  cerr << a.size() << ":{";
  for (auto v : a) Err(v);
  cerr << "}";
  Err(x...);
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rnd(long long l, long long r) {
  return uniform_int_distribution<long long>(l, r)(rng);
}
template <class T>
void Min(T &a, const T b) {
  if (a > b) a = b;
}
template <class T>
void Max(T &a, const T b) {
  if (a < b) a = b;
}
const long long linf = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int N = 400 + 10, M = 500;
const long long mod = 998244353;
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  ;
  long long k, A, h;
  cin >> k >> A >> h;
  long long p[6]{1, 2, 3, 5, 9, 17};
  long long base[6]{};
  for (int i = 0; i < 6; i++) {
    base[i] = 1;
    for (int j = 0; j < p[i]; j++) (base[i] *= A) %= mod;
  }
  int n = 1 << k;
  auto encrypt = [&](int S, int add) {
    pair<long long, vector<int> > ret{0, vector<int>(n / 2)};
    for (int i = 0; i < n / 2; i++) {
      int j = k, t = i, s = S;
      while (j && (s >> t / 2 & 1 ^ t & 1)) j--, t /= 2, s >>= 1 << j - 1;
      (ret.first += base[j] * (i + add) % mod) %= mod;
      ret.second[i] = p[j];
    }
    return ret;
  };
  map<long long, vector<int> > mp[2];
  for (int i = 0; i < 1 << n / 2; i++) mp[i < 1 << n / 4].insert(encrypt(i, 1));
  for (int i = 0; i < 1 << n / 2; i++) {
    auto u = encrypt(i, 1 + n / 2);
    long long t = (h - u.first + mod) % mod;
    if (mp[i < 1 << n / 4].count(t)) {
      for (auto i : mp[i < 1 << n / 4][t]) cout << i << ' ';
      for (auto i : u.second) cout << i << ' ';
      return 0;
    }
  }
  cout << -1;
}

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
  cerr << '(' << a.first << ',' << a.second << "),";
  Err(x...);
}
template <template <class...> class T, class t, class... A>
void Err(T<t> a, A... x) {
  cerr << a.size() << ":{";
  for (auto v : a) Err(v);
  cerr << "},";
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
const int N = 2e7 + 10, M = 500;
const long long mod = 1e9 + 7;
const long double eps = 1e-8;
int sgn(long double a) { return a < -eps ? -1 : (a < eps ? 0 : 1); }
int solve() {
  int n, ret;
  cin >> n;
  vector<int> ar(n);
  for (auto &i : ar) cin >> i;
  sort(ar.begin(), ar.end());
  if (ar.back() % 3 == 2) {
    ret = ar.back() / 3 + 1;
    for (auto i : ar)
      if (i % 3 == 1) {
        ret++;
        break;
      }
  } else if (ar.back() % 3 == 1) {
    ret = ar.back() / 3 + 1;
    bool f1 = 1, f2 = 1;
    for (auto i : ar) {
      if (i % 3 == 2) f1 = 0;
      if (i == ar.back() - 1) f2 = 0;
    }
    if (!f1 && !f2) ret++;
  } else {
    ret = ar.back() / 3;
    for (auto i : ar) {
      if (i % 3) {
        ret++;
        break;
      }
    }
  }
  return ret;
}
int main() {
  ;
  ios::sync_with_stdio(0), cin.tie(0);
  int _;
  cin >> _;
  while (_--) {
    cout << solve() << '\n';
  }
}

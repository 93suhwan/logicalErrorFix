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
const int N = 5e5 + 10;
const long long mod = 998244353;
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  ;
  int n, d;
  cin >> n >> d;
  vector<array<int, 4>> ar(n);
  for (int i = 0; i < n; i++) {
    int s, a;
    cin >> s >> a;
    ar[i] = {max(s, a), min(s, a), s, a};
  }
  sort(ar.begin(), ar.end());
  int ans = 0;
  for (auto i : ar) {
    int s = i[2], a = i[3];
    if (s >= d) {
      ans++;
      Max(d, a);
    }
  }
  cout << ans;
}

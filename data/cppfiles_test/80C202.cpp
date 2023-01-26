#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lpair = pair<ll, ll>;
using vll = vector<ll>;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
ostream& operator<<(ostream& os, lpair& h) {
  os << "(" << h.first << ", " << h.second << ")";
  return os;
}
void print() {}
template <class H, class... T>
void print(H&& h, T&&... t) {
  cout << h << " \n"[sizeof...(t) == 0];
  print(forward<T>(t)...);
}
template <class T>
bool chmax(T& a, const T& b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T& a, const T& b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
ll power(ll x, ll n, ll m = MOD) {
  if (n == 0) return 1LL;
  ll res = power(x * x % m, n / 2, m);
  if (n % 2 == 1) (res *= x) %= m;
  return res;
}
typedef struct {
  ll l, r, p;
} P;
void solve() {
  ll N;
  cin >> N;
  string S;
  cin >> S;
  for (ll i = (N / 2); i < (N); i++) {
    if (S[i] == '0') {
      print(1, i + 1, 1, i);
      return;
    }
  }
  for (ll i = (0); i < (N); i++) {
    if (S[i] == '0') {
      print(i + 1, N, i + 2, N);
      return;
    }
  }
  print(1, N - 1, 2, N);
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll t;
  cin >> t;
  while (t--) solve();
}

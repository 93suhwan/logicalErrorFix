#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ui = unsigned int;
using ii = pair<int, int>;
using ull = unsigned long long;
using vi = vector<int>;
using vii = vector<ii>;
using llp = pair<ll, ll>;
const ll MAXN = 1e3 + 100, MAXM = 100 + 100, LOG_MAXN = 20, MAXVAL = 2e6 + 100,
         MOD = 1e9 + 7, INF = 1e9 + 7;
template <class A, class B>
ostream &operator<<(ostream &strm, pair<A, B> p) {
  return strm << "{" << p.first << ";" << p.second << "}";
}
template <class A, class B>
ostream &operator<<(ostream &strm, vector<A, B> &v) {
  for (int i = 0; i < v.size(); i++)
    strm << v[i] << ((i + 1 == v.size()) ? "" : " ");
  return strm;
}
bool isLessThanSquare(ll i, ll n) { return i * i <= n; }
bool isLessThanCube(ll i, ll n) { return i * i <= n / i; }
ll bin_search(ll n, bool (*prop)(ll a, ll b)) {
  ll beg = 0, end = n + 1;
  while (end - beg > 1) {
    ll m = ((beg + end) / 2);
    if (prop(m, n))
      beg = m;
    else
      end = m;
  }
  return beg;
}
ll getSixRoot(ll n) {
  ll x = bin_search(n, isLessThanCube);
  return bin_search(x, isLessThanSquare);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  ;
  ;
  ;
  int t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    ll sq = bin_search(n, isLessThanSquare);
    ll cb = bin_search(n, isLessThanCube);
    ll six = getSixRoot(n);
    cout << sq + cb - six << '\n';
  }
}

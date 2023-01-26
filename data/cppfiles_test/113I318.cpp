#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = (int)3e5 + 117;
const int MOD = (int)1e9 + 7;
const int BASE = 31;
const int MAX = (int)1e6;
const int INF = (int)1e9 + 117;
const ll INFll = (ll)2e18 + 117;
template <class T>
istream& operator>>(istream& in, vector<T>& v) {
  for (auto& i : v) in >> i;
  return in;
}
template <class T>
ostream& operator<<(ostream& out, vector<T>& v) {
  for (auto& i : v) out << i << " ";
  return out;
}
void solve();
signed int main() {
  freopen("/Users/georgij/Documents/code/io/input.txt", "r", stdin);
  freopen("/Users/georgij/Documents/code/io/output.txt", "w", stdout);
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout.precision(10);
  cout.setf(ios::fixed);
  srand(random_device()());
  int t = 1;
  while (t--) solve();
  return 0;
}
void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  cin >> a;
  ll s = 0;
  for (auto& i : a) s += i;
  ll m;
  cin >> m;
  while (m--) {
    ll x, y;
    cin >> x >> y;
    ll mn = 0;
    for (ll i = 1; i < n; ++i) {
      if (abs(a[mn] - x) > abs(a[i] - x)) mn = i;
    }
    ll add = 0;
    if (a[mn] < x) add += x - a[mn];
    if (s - a[mn] < y) add += y - s + a[mn];
    cout << add << "\n";
  }
}

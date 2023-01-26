#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = (int)3e5 + 117;
const int MOD = (int)1e9 + 7;
const int BASE = 31;
const int MAX = (int)1e6;
const int INF = (int)1e9 + 117;
const ll INFll = INT64_MAX;
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
  sort(a.begin(), a.end());
  while (m--) {
    ll x, y;
    cin >> x >> y;
    auto j = upper_bound(a.begin(), a.end(), x) - a.begin();
    ll ans1 = 0;
    ll ans2 = 0;
    if (j > 0) {
      if (a[j - 1] < x)
        ans1 = x - a[j - 1];
      else
        ans1 = 0;
      if (s - a[j - 1] < y) ans1 += y - s + a[j - 1];
    }
    if (j < n) {
      if (a[j] < x)
        ans2 = x - a[j];
      else
        ans2 = 0;
      if (s - a[j] < y) ans2 += y - s + a[j];
    }
    cout << min(ans1, ans2) << "\n";
  }
}

#include <bits/stdc++.h>
using namespace std;
template <typename A>
ostream &operator<<(ostream &cout, vector<A> const &v) {
  cout << "[";
  for (int i = 0; i < v.size(); i++) {
    if (i) cout << ", ";
    cout << v[i];
  }
  return cout << "]";
}
template <typename A, typename B>
ostream &operator<<(ostream &cout, pair<A, B> const &p) {
  return cout << "(" << p.first << ", " << p.second << ")";
}
template <typename A, typename B>
istream &operator>>(istream &cin, pair<A, B> &p) {
  cin >> p.first;
  return cin >> p.second;
}
int drx[] = {1, -1, 0, 0};
int dry[] = {0, 0, 1, -1};
void caseNumber(int x) { printf("Case %d: ", x); }
void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }
int gray_code(int n) { return n ^ (n >> 1); }
int turnOn(int x, int pos) { return x | (1 << pos); }
int turnOff(int x, int pos) { return x & !(1 << pos); }
bool isOn(int x, int pos) { return (bool)(x & (1 << pos)); }
double geo_dis(double x1, double y1, double x2, double y2) {
  double d1 = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
  d1 = sqrt(d1);
  return d1;
}
long long int const mod_t = 1000000007;
long long int const inf = 3e18 + 9;
long long int const mod = 1e9 + 7;
long long int const MAX = 1000005;
long long int const maxn = 1e3 + 9;
long long int const new_mod = 998244353;
bool comp(pair<int, int> a, pair<int, int> b) { return a.first < b.first; }
void solve() {
  int n, k;
  cin >> n >> k;
  vector<pair<int, int> > a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a.begin(), a.end(), comp);
  int c = 1;
  for (int i = 1; i < n; i++) {
    if (a[i].second - 1 == a[i - 1].second) {
    } else
      c++;
  }
  if (c <= k)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tc;
  cin >> tc;
  while (tc--) solve();
}

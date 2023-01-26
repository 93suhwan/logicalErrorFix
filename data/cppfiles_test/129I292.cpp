#include <bits/stdc++.h>
using namespace std;
bool spc;
template <typename T, typename U>
istream& operator>>(istream& i, pair<T, U>& p) {
  i >> p.first >> p.second;
  return i;
}
template <typename T, typename U>
ostream& operator<<(ostream& o, pair<T, U>& p) {
  o << p.first << ' ' << p.second;
  return o;
}
template <typename T>
istream& operator>>(istream& i, vector<T>& v) {
  for (auto& el : v) i >> el;
  return i;
}
template <typename T>
ostream& operator<<(ostream& o, vector<T>& v) {
  for (auto& el : v) {
    spc = 0;
    cout << el;
    if (!spc) cout << ' ';
  }
  spc = 1;
  cout << '\n';
  return o;
}
void solve();
void solvet() {
  int t;
  cin >> t;
  for (long long __ = (0); __ < (t); __++) solve();
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout.precision(20);
  ;
  solvet();
  return 0;
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  cin >> a;
  sort((a).begin(), (a).end());
  long long ans = 0;
  for (long long i = (0); i < (n); i++) {
    if (a[i] != i + 1) ans++;
    if (a[i] < i + 1 || a[i] != i + 1 && a[i] - (i + 1) <= i + 1) {
      cout << -1 << endl;
      return;
    }
  }
  cout << ans << endl;
}

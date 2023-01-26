#include <bits/stdc++.h>
#pragma GCC optimize "trapv"
using namespace std;
template <typename T1, typename T2>
istream &operator>>(istream &istream, pair<T1, T2> &p) {
  return (istream >> p.first >> p.second);
}
template <typename T>
istream &operator>>(istream &istream, vector<T> &v) {
  for (auto &it : v) cin >> it;
  return istream;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &ostream, const pair<T1, T2> &p) {
  return (ostream << p.first << " " << p.second);
}
template <typename T>
ostream &operator<<(ostream &ostream, const vector<T> &c) {
  for (auto &it : c) cout << it << " ";
  return ostream;
}
vector<pair<long long int, long long int> > dir = {
    {0, 1}, {1, 0}, {-1, 0}, {0, -1}};
void solve() {
  long long int n;
  cin >> n;
  vector<long long int> v(n);
  cin >> v;
  vector<long long int> vc = v;
  sort((vc).begin(), (vc).end());
  long long int a = 0;
  for (long long int i = 0; 0 < n ? i < n : i > n; 0 < n ? i += 1 : i -= 1)
    a += (vc[i] != v[i]);
  if (a == 0 || (a >= 3 && a <= 9))
    cout << "YES";
  else if (a < 3)
    cout << "NO";
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  cout << fixed << setprecision(0);
  long long int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
  };
  return 0;
}

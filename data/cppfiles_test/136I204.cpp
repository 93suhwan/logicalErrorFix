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
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
void solve() {
  long long n;
  cin >> n;
  vector<long long> b(n);
  cin >> b;
  long long t = 0;
  for (auto& el : b) t += el;
  long long cnt = n * (n + 1) / 2;
  if (t % cnt != 0) {
    cout << "NO\n";
    return;
  }
  t /= cnt;
  vector<long long> ans;
  for (long long i = (0); i < (n); i++) {
    ans.push_back((b[(n - 1 + i) % n] - b[i] + t) / n);
    if ((b[(n - 1 + i) % n] - b[i] + t) % n != 0 || ans[i] == 0) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n" << ans;
}

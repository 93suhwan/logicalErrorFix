#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1000000000,1000000000")
using namespace std;
template <class T>
istream& operator>>(istream& is, vector<T>& vec) {
  for (int i = 0; i < (int)vec.size(); ++i) is >> vec[i];
  return is;
}
template <class T>
ostream& operator<<(ostream& os, vector<T>& vec) {
  for (int i = 0; i < (int)vec.size(); ++i) os << vec[i] << " ";
  return os;
}
template <class T>
istream& operator>>(istream& is, pair<T, T>& a) {
  is >> a.first >> a.second;
  return is;
}
const double pi = acos(-1.0);
const long long mod = 998244353;
const long long INF = 2e18;
const int inf = (int)1e9 + 7;
const int maxlen = (int)1e5 + 100;
const double eps = 1e-7;
void solve() {
  int n;
  cin >> n;
  int mx = -1, mx_n, mn_n = -1;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (a > mx) {
      if (a == mx + 1) {
        mn_n = mx_n;
      } else
        mn_n = 0;
      mx = a;
      mx_n = 0;
    }
    if (a == mx) mx_n++;
    if (a == mx - 1) mn_n++;
  }
  if (mx_n == 1 && mn_n == 0) {
    cout << 0 << endl;
    return;
  }
  if (mx_n > 1) {
    long long fact = 1;
    for (int i = 2; i <= n; i++) {
      fact = (fact * i) % mod;
    }
    cout << fact << endl;
    return;
  }
  long long fact = 1;
  for (int i = 2; i <= n - 2; i++) {
    if (i != mn_n - 1) fact = (fact * i) % mod;
  }
  long long sum = 0;
  for (int i = n - 1; i > 0; i--) {
    sum = (sum + (i * fact) % mod) % mod;
  }
  sum = (sum * mn_n) % mod;
  cout << sum << endl;
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

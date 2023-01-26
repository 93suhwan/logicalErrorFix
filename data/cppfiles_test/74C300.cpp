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
const long long mod = (int)1e9 + 7;
;
const long long INF = 2e18;
const int inf = (int)1e9 + 7;
const int maxlen = (int)1e5 + 100;
const double eps = 1e-7;
void solve() {
  int a, b;
  cin >> a >> b;
  if (a > b) swap(a, b);
  int n = a + b;
  int ans = 0;
  vector<int> v;
  if (n % 2 == 1) {
    int k = n / 2;
    for (int i = k - a; i <= k + a + 1; i += 1) {
      ans++;
      v.push_back(i);
    }
  } else {
    int k = n / 2;
    for (int i = k - a; i <= k + a; i += 2) {
      ans++;
      v.push_back(i);
    }
  }
  cout << ans << endl;
  for (auto x : v) {
    cout << x << " ";
  }
  cout << endl;
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

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
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      cout << "(";
    }
    for (int j = 0; j < n - i; j++) {
      cout << "()";
    }
    for (int j = 0; j < i; j++) {
      cout << ")";
    }
    cout << endl;
  }
}
int main() {
  cin.sync_with_stdio(false);
  cout.sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

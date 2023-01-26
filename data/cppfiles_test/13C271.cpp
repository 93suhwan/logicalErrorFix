#include <bits/stdc++.h>
using namespace std;
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  for (long long i = 0; i < v.size(); ++i) {
    os << v[i] << " ";
  }
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<vector<T>> &v) {
  for (long long i = 0; i < v.size(); ++i) {
    for (long long j = 0; j < v[i].size(); j++) os << v[i][j] << "";
    cout << "\n";
  }
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<pair<T, T>> &v) {
  for (long long i = 0; i < v.size(); ++i) {
    os << v[i].first << " " << v[i].second << "\n";
  }
  return os;
}
void solve() {
  string s;
  cin >> s;
  long long cnta = 0, cntb = 0, cntc = 0;
  long long n = s.length();
  for (long long i = 0; i < n; i++) {
    if (s[i] == 'A')
      cnta++;
    else if (s[i] == 'B')
      cntb++;
    else
      cntc++;
  }
  if (cntb == ((cnta + cntc))) {
    cout << "YES"
         << "\n";
  } else
    cout << "NO"
         << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  for (long long x = 0; x < t; x++) {
    solve();
  }
  return 0;
}

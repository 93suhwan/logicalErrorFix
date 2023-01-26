#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline istream &operator>>(istream &s, vector<T> &v) {
  for (T &t : v) {
    s >> t;
  }
  return s;
}
template <typename T>
inline ostream &operator<<(ostream &s, const vector<T> &v) {
  for (int i = 0; i < int(v.size()); ++i) {
    s << (" " + !i) << v[i];
  }
  return s;
}
template <typename T>
inline T fromString(const string &s) {
  T res;
  istringstream iss(s);
  iss >> res;
  return res;
};
template <typename T>
inline string toString(const T &a) {
  ostringstream oss;
  oss << a;
  return oss.str();
};
const long long mod = 1000000007;
const long long INF = 1e18;
int main() {
  long long t;
  t = 1;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    char s[2][n];
    for (int i = (0); i < (2); i++) {
      for (int j = (0); j < (n); j++) {
        cin >> s[i][j];
      }
    }
    long long f = 0;
    for (int i = (0); i < (1); i++) {
      for (int j = (0); j < (n); j++) {
        if (s[i][j] == '1' && s[i + 1][j] == '1') {
          f = 1;
        }
      }
    }
    if (f) {
      cout << "NO"
           << "\n";
    } else {
      cout << "YES"
           << "\n";
    }
  }
}

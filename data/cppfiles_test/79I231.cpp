#include <bits/stdc++.h>
using namespace std;
void _print(long long t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p) {
  cerr << "{";
  _print(p.first);
  cerr << ",";
  _print(p.second);
  cerr << "}";
}
template <class T>
void _print(vector<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(multiset<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
const long long MOD = 1e9 + 7;
void solve() {
  long long k;
  cin >> k;
  string s;
  cin >> s;
  long long n;
  sort(s.begin(), s.end());
  for (long long i = 0; i < k; i++) {
    n = s[i] - '0';
    if (n == 1 || n == 9 || (n != 2 && n % 2 == 0)) {
      cout << 1 << '\n';
      cout << n << '\n';
      return;
    }
  }
  string ans = "";
  for (long long i = 0; i < k; i++) {
    n = s[i] - '0';
    if (i < k && s[i] == s[i + 1]) {
      ans = ans + s[i] + s[i];
      cout << 2 << '\n';
      cout << ans << '\n';
      return;
    }
  }
  for (long long i = 0; i < k; i++) {
    n = s[i] - '0';
    if (n == 2 || n == 5) {
      ans = "";
      cout << 2 << '\n';
      if (i == 0)
        ans = ans + s[i + 1] + s[i];
      else
        ans = ans + s[i - 1] + s[i];
      cout << ans << '\n';
      return;
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}

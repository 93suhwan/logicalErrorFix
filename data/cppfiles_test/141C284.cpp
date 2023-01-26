#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const double pi = 3.14159265358979323846;
const long long mxN = 2e5 + 1;
void _print(long long t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(double t) { cerr << t; }
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
void solve() {
  string a, s;
  cin >> a >> s;
  reverse(a.begin(), a.end());
  reverse(s.begin(), s.end());
  if (a.length() > s.length()) {
    cout << -1 << '\n';
    return;
  }
  long long i = 0, j = 0;
  string ans = "";
  while (i < a.length()) {
    long long here = a[i] - '0';
    long long one = -1;
    if (j < s.length()) one = s[j] - '0';
    long long two = -1;
    if (j + 1 < s.length()) two = s[j] - '0' + (s[j + 1] - '0') * 10;
    if (one - here >= 0 && one - here <= 9) {
      ans += ((one - here) + '0');
      j++;
    } else if (two - here >= 0 && two - here <= 9) {
      ans += ((two - here) + '0');
      j += 2;
    } else {
      cout << -1 << '\n';
      return;
    }
    i++;
  }
  while (j < s.length()) {
    ans += s[j];
    j++;
  }
  reverse(ans.begin(), ans.end());
  string fin = "";
  for (i = 0; i < ans.length(); i++) {
    if (ans[i] == '0')
      ;
    else
      break;
  }
  if (i == ans.length())
    cout << 0 << '\n';
  else
    cout << ans.substr(i) << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}

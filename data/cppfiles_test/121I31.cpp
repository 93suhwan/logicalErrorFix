#include <bits/stdc++.h>
using namespace std;
void _print(long long int t) { cerr << t; }
void _print(int t) { cerr << t; }
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
long long int add(long long int x, long long int y) {
  long long int ans = x + y;
  return (ans >= 1000000007 ? ans - 1000000007 : ans);
}
long long int sub(long long int x, long long int y) {
  long long int ans = x - y;
  return (ans < 0 ? ans + 1000000007 : ans);
}
long long int mul(long long int x, long long int y) {
  long long int ans = x * y;
  return (ans >= 1000000007 ? ans % 1000000007 : ans);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  srand(time(NULL));
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    vector<long long int> e, ue;
    bool ok = 0;
    for (long long int i = 0; i < s1.length(); ++i)
      if (s1[i] == '1') ok = 1;
    for (long long int i = 0; i < s1.length(); ++i) {
      if (s1[i] == s2[i])
        e.push_back(i);
      else
        ue.push_back(i);
    }
    long long int ans = INT_MAX, k1 = e.size(), k2 = ue.size();
    if (k2 % 2 == 0 && ok) ans = min(ans, k2);
    if ((k1 & 1) && ok) ans = min(ans, k1);
    if (ans == INT_MAX)
      cout << -1 << '\n';
    else
      cout << ans << '\n';
  }
  return 0;
}

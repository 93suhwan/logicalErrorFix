#include <bits/stdc++.h>
using namespace std;
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
const long long inf = 9223372036854775807;
const long long mod = 1000000007;
const double pi = acos(-1);
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    string s;
    cin >> s;
    multiset<int, greater<int>> red;
    multiset<int> blue;
    set<int> se;
    for (int i = 0; i < n; i++) {
      se.insert(a[i]);
      if (s[i] == 'R') {
        red.insert(a[i]);
      } else {
        blue.insert(a[i]);
      }
    }
    for (int i = 1; i < n + 1; i++) {
      if (blue.size() == 0) {
        break;
      }
      if (se.find(i) == se.end()) {
        auto j = blue.begin();
        blue.erase(j);
        se.insert(i);
      }
      blue.erase(i);
    }
    for (int i = n; i >= 1; i--) {
      if (red.size() == 0) {
        break;
      }
      if (se.find(i) == se.end()) {
        auto j = red.begin();
        red.erase(j);
        se.insert(i);
      }
      red.erase(i);
    }
    int flag = 1;
    for (int i = 1; i < n + 1; i++) {
      if (se.find(i) == se.end()) {
        flag = 0;
        break;
      }
    }
    if (flag == 1) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long int mod = 1e9 + 7;
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char* x) { cerr << '\"' << x << '\"'; }
void __print(const string& x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V>& x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T& x) {
  int f = 0;
  cerr << '{';
  for (auto& i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
template <typename T>
void print(vector<T> v) {
  for (T i : v) cout << i << " ";
  cout << '\n';
}
template <typename T>
void print(vector<vector<T>>& v) {
  for (vector<T>& vv : v) {
    for (T& i : vv) cout << i << " ";
    cout << '\n';
  }
}
template <typename T>
void read(vector<T>& v) {
  for (T& i : v) cin >> i;
}
template <typename T>
void read(T&& t) {
  cin >> t;
}
template <typename T, typename... Args>
void read(T&& t, Args&&... args) {
  cin >> t;
  read(forward<Args>(args)...);
}
template <typename T>
void print(T&& t) {
  cout << t << '\n';
}
template <typename T, typename... Args>
void print(T&& t, Args&&... args) {
  cout << t << " ";
  print(forward<Args>(args)...);
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ;
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int done = 0;
    for (int i = 0; i < n / 2; i++) {
      if (s[i] == '0') {
        done = 1;
        cout << i + 1 << " " << n << endl;
        cout << i + 2 << " " << n << endl;
        break;
      }
    }
    if (done) continue;
    for (int i = n / 2; i < n; i++) {
      if (s[i] == '0') {
        done = 1;
        cout << 1 << " " << i + 1 << endl;
        cout << 1 << " " << i << endl;
        break;
      }
    }
    if (done) continue;
    cout << 1 << " " << n - 1 << endl;
    cout << 2 << " " << n << endl;
  }
}

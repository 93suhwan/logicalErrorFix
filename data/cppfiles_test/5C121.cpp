#include <bits/stdc++.h>
using namespace std;
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
template <typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;
long long int gcd(long long int a, long long int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long int mod = 1000000007;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long long int inf = 100000000000000;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    long long int c = 0;
    for (long long int i = 0; i < n; i++) {
      if (b[i] == '1') {
        if (i == 0) {
          if (a[i] == '0') {
            c++;
          } else {
            if (a[i + 1] == '1') {
              c++;
              a[i + 1] = '0';
            }
          }
        } else if (i == n - 1) {
          if (a[i] == '0') {
            c++;
          } else {
            if (a[i - 1] == '1') {
              c++;
              a[i - 1] = '0';
            }
          }
        } else {
          if (a[i] == '0') {
            c++;
          } else {
            if (a[i - 1] == '1') {
              c++;
              a[i - 1] = '0';
            } else if (a[i + 1] == '1') {
              c++;
              a[i + 1] = '0';
            }
          }
        }
      }
    }
    cout << c << "\n";
  }
  return 0;
}

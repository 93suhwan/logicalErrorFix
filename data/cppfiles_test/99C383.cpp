#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
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
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long int a, b;
    cin >> a >> b;
    if (b == 0)
      cout << a << endl;
    else if ((b - 1) % 4 == 0) {
      if (a & 1)
        cout << a + b << endl;
      else
        cout << a - b << endl;
    } else if ((b - 1) % 4 == 1) {
      if (a & 1)
        cout << a + (b - 1) - b << endl;
      else
        cout << a - (b - 1) + b << endl;
    } else if ((b - 1) % 4 == 2) {
      if (a & 1)
        cout << a + (b - 2) - (b + (b - 1)) << endl;
      else
        cout << a - (b - 2) + (b + (b - 1)) << endl;
    } else if ((b - 1) % 4 == 3) {
      if (a & 1)
        cout << a + ((b - 3) + b) - ((b - 2) + (b - 1)) << endl;
      else
        cout << a - ((b - 3) + b) + ((b - 2) + (b - 1)) << endl;
    }
  }
}

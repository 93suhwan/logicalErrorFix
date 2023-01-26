#include <bits/stdc++.h>
using namespace std;
void show(vector<long long> &a) {
  for (long long e : a) {
    if (e == (long long)(1e18 + 5))
      cout << "INF ";
    else
      cout << e << " ";
  }
  cout << "\n";
}
void show(vector<int> &a) {
  for (int e : a) {
    if (e == (long long)(1e9 + 7))
      cout << "MOD ";
    else
      cout << e << " ";
  }
  cout << "\n";
}
template <typename T>
void enter(vector<T> &a) {
  for (T &e : a) cin >> e;
}
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
  int first = 0;
  cerr << '{';
  for (auto &i : x) cerr << (first++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
void JUDGE() {}
long long inline mo(long long a) { return a % (long long)(1e9 + 7); }
long long po(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y >>= 1;
    x = (x * x) % p;
  }
  return res % p;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<int> a(n);
  enter(a);
  int li = (1 << 9);
  vector<int> val(li, (long long)(1e9 + 7));
  val[0] = -1;
  for (int i = 0; i < n; i++) {
    vector<int> new_val = val;
    for (int mask = 0; mask < li; mask++) {
      if (val[mask] < a[i]) {
        int next = (mask ^ a[i]);
        new_val[next] = min(new_val[next], a[i]);
      }
    }
    val = new_val;
  }
  vector<int> ans;
  for (int i = 0; i < li; i++) {
    if (val[i] < (long long)(1e9 + 7)) ans.push_back(i);
  }
  cout << (int)ans.size() << "\n";
  for (int e : ans) cout << e << " ";
  cout << "\n";
  return 0;
}

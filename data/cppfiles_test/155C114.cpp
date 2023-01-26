#include <bits/stdc++.h>
using namespace std;
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
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
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        std::chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
const long long INF = 9223372036854775807;
const long long N = 2e5 + 5;
const long long mod = 998244353;
const long long M = 22;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n + 2];
    for (long long i = 1; i <= n; i++) cin >> a[i];
    string s;
    cin >> s;
    long long x = 0;
    set<pair<long long, long long> > st;
    map<long long, long long> m;
    for (long long i = 0; i < n; i++) {
      m[a[i + 1]] = i + 1;
      if (s[i] == '0') {
        x++;
      }
    }
    set<long long> p;
    for (long long i = 0; i < n; i++) {
      if (s[i] == '0' && a[i + 1] > x) st.insert({a[i + 1], i + 1});
      if (s[i] == '1' && a[i + 1] <= x) p.insert(a[i + 1]);
    }
    for (auto k : st) {
      a[k.second] = *p.begin();
      a[m[*p.begin()]] = k.first;
      p.erase(p.begin());
    }
    for (long long i = 1; i <= n; i++) cout << a[i] << " ";
    cout << '\n';
  }
}

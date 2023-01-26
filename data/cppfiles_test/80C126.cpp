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
const long long N = 500005;
const long long mod = 1e9 + 7;
const long long M = 22;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    string s;
    cin >> s;
    long long ok = 0;
    long long f = 0;
    for (long long i = 0; i < n; i++) {
      if (s[i] == '0') {
        ok = i;
        f = 1;
        break;
      }
    }
    if (!f) {
      long long l2 = 0, r2 = (n / 2) - 1;
      long long l1 = 0, r1 = 2 * (n / 2) - 1;
      l1++, l2++, r1++, r2++;
      cout << l1 << " " << r1 << " " << l2 << " " << r2 << '\n';
      continue;
    }
    long long k = (n / 2);
    if (n % 2) k++;
    if (ok < k) {
      long long l2 = ok + 1, r2 = n - 1;
      long long l1 = ok, r1 = n - 1;
      l1++, l2++, r1++, r2++;
      cout << l1 << " " << r1 << " " << l2 << " " << r2 << '\n';
    } else {
      long long l2 = 0, r2 = ok - 1;
      long long l1 = 0, r1 = ok;
      l1++, l2++, r1++, r2++;
      cout << l1 << " " << r1 << " " << l2 << " " << r2 << '\n';
    }
  }
}

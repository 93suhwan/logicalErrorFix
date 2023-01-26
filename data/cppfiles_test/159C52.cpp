#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
template <class T>
bool ckmin(T &a, const T &b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnd(time(nullptr));
void __print(long long first) { cerr << first; }
void __print(long first) { cerr << first; }
void __print(unsigned first) { cerr << first; }
void __print(unsigned long first) { cerr << first; }
void __print(unsigned long long first) { cerr << first; }
void __print(float first) { cerr << first; }
void __print(double first) { cerr << first; }
void __print(long double first) { cerr << first; }
void __print(char first) { cerr << '\'' << first << '\''; }
void __print(const char *first) { cerr << '\"' << first << '\"'; }
void __print(const string &first) { cerr << '\"' << first << '\"'; }
void __print(bool first) { cerr << (first ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &first) {
  cerr << '{';
  __print(first.first);
  cerr << ", ";
  __print(first.second);
  cerr << '}';
}
template <typename T>
void __print(const T &first) {
  long long f = 0;
  cerr << '{';
  for (auto &i : first) cerr << (f++ ? ", " : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
const long long N = 1e6 + 5;
vector<long long> fact[N];
long long val[N], hsh[N];
bool try_(long long n) {
  long long res = 0;
  for (long long i = 2; i <= n; ++i) {
    res ^= val[i];
  }
  if (res == 0) {
    cout << n << "\n";
    for (long long i = 1; i <= n; ++i) {
      cout << i << " ";
    }
    return true;
  }
  for (long long i = 2; i <= n; ++i) {
    if (val[i] == res) {
      cout << n - 1 << "\n";
      for (long long j = 1; j <= n; ++j) {
        if (i != j) {
          cout << j << " ";
        }
      }
      return true;
    }
  }
  map<long long, long long> was;
  for (long long i = 2; i <= n; ++i) {
    if (was.count(val[i] ^ res)) {
      cout << n - 2 << "\n";
      for (long long j = 1; j <= n; ++j) {
        if (i != j && j != was[val[i] ^ res]) {
          cout << j << " ";
        }
      }
      return true;
    }
    was[val[i]] = i;
  }
  return false;
}
void solve() {
  long long n;
  cin >> n;
  for (long long i = 2; i <= n; ++i) {
    hsh[i] = uniform_int_distribution<long long>(1, (1LL << 62) - 1)(rng);
    if (!fact[i].empty()) continue;
    for (long long j = i; j <= n; j *= i) {
      for (long long k = j; k <= n; k += j) {
        fact[k].push_back(i);
      }
    }
  }
  for (long long i = 2; i <= n; ++i) {
    val[i] = val[i - 1];
    for (long long d : fact[i]) {
      val[i] ^= hsh[d];
    }
  }
  if (!try_(n)) try_(n - 1);
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) solve();
}

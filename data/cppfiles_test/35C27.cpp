#include <bits/stdc++.h>
using namespace std;
template <class T>
bool ckmin(T &a, const T &b) {
  return a > b ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
namespace debug {
void __print(int x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
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
  for (auto z : x) cerr << (f++ ? "," : ""), __print(z);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
}  // namespace debug
using namespace debug;
const char nl = '\n';
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
const int mxN = 1e6 + 12;
int lp[mxN];
void precalc() {
  vector<int> primes;
  for (int i = 2; i < mxN; ++i) {
    if (lp[i] == 0) {
      lp[i] = i;
      primes.push_back(i);
    }
    for (int j = 0; j < (int)(primes).size() && primes[j] <= lp[i] &&
                    primes[j] * 1LL * i < mxN;
         ++j) {
      lp[primes[j] * i] = primes[j];
    }
  }
}
vector<int> gde[mxN];
const int LOG = 24;
int sparse[mxN][LOG];
void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &z : v) cin >> z;
  string s;
  cin >> s;
  vector<int> granica(n);
  for (int i = 0; i < n; ++i) {
    int x = v[i];
    if (s[i] == '*') {
      granica[i] = i;
      while (x > 1) {
        gde[lp[x]].push_back(i);
        x /= lp[x];
      }
    } else {
      granica[i] = i;
      while (x > 1) {
        int tren = lp[x];
        if ((int)(gde[tren]).size() == 0) {
          granica[i] = -1;
          x /= tren;
          continue;
        }
        ckmin(granica[i], gde[tren].back());
        gde[tren].pop_back();
        x /= tren;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    sparse[i][0] = granica[i];
  }
  for (int iter = 1; iter < LOG; ++iter) {
    for (int i = 0; i + (1 << iter) - 1 < n; ++i) {
      int drugi = (1 << (iter - 1)) + i;
      sparse[i][iter] = min(sparse[i][iter - 1], sparse[drugi][iter - 1]);
    }
  }
  auto query = [&](int l, int r) {
    int duz = r - l + 1;
    int treba = 31 - __builtin_clz(duz);
    int levi = l;
    int desni = r - (1 << treba) + 1;
    return min(sparse[levi][treba], sparse[desni][treba]);
  };
  long long odg = 0;
  for (int i = 0; i < n; ++i) {
    int l = i, r = n - 1;
    int ans = -1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (query(i, mid) == i) {
        ans = mid;
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    if (ans >= i) {
      odg += (ans - i + 1);
    }
  }
  cout << odg << nl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  precalc();
  int testCases = 1;
  while (testCases--) solve();
}
